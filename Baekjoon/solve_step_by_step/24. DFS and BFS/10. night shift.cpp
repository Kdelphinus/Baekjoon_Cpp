/**
 * @file 10. night shift.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief
 * @date 2021-10-14 19:50:09
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

// 나이트가 이동할 수 있는 위치
int direction[8][2] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

int BFS(int n, pair<int, int> current, pair<int, int> goal)
{
    int visited[n][n] = {}; // 지나갔는지 체크할 체스판
    int x, y, cnt;          // 좌표 성분과 몇 번 옮겼는지 저장할 변수
    int nx, ny;
    queue<tuple<int, int, int>> q;
    q.push({current.first, current.second, 0}); // x좌표, y좌표, 옮긴 횟수
    visited[current.second][current.first] = 1;

    while (!q.empty())
    {
        x = get<0>(q.front());
        y = get<1>(q.front());
        cnt = get<2>(q.front());
        q.pop();

        if (x == goal.first && y == goal.second)
            return cnt;

        for (int i = 0; i < 8; i++)
        {
            nx = x + direction[i][0];
            ny = y + direction[i][1];

            if (0 <= nx && nx < n && 0 <= ny && ny < n && visited[ny][nx] == 0)
            {
                visited[ny][nx] = 1;
                q.push({nx, ny, cnt + 1});
            }
        }
    }
}

int main()
{
    int test;
    cin >> test;

    for (int t = 0; t < test; t++)
    {
        int n;
        pair<int, int> current, goal;
        cin >> n;
        cin >> current.first >> current.second;
        cin >> goal.first >> goal.second;

        cout << BFS(n, current, goal) << '\n';
    }
    return 0;
}