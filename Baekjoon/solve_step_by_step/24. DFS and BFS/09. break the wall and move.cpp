/**
 * @file 09. break the wall and move.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief
 * @date 2021-10-14 19:31:05
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int width, height;
int map[1001][1001];
int visited[1001][1001][2];
int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int x, y, wall, cnt;
int nx, ny;

int BFS()
{
    queue<vector<int>> q;
    q.push({0, 0, 0, 1}); // x좌표, y좌표, 벽을 부순 횟수, 이동 거리
    visited[0][0][0] = 1; // (0, 0)의 위치에서 벽을 부수지 않은 채 방문한 적 있음

    while (!q.empty())
    {
        x = q.front()[0];
        y = q.front()[1];
        wall = q.front()[2];
        cnt = q.front()[3];
        q.pop();

        if (x == width - 1 && y == height - 1) // 위치에 도달했을 때
            return cnt;

        for (int i = 0; i < 4; i++)
        {
            nx = x + direction[i][0];
            ny = y + direction[i][1];

            if (0 <= nx && nx < width && 0 <= ny && ny < height) // 좌표가 범위 안에 있을 때
            {
                // 벽을 이미 부셨고 지나갈 수 있을 때
                if (wall == 1 && visited[ny][nx][1] == 0 && map[ny][nx] == 0)
                {
                    visited[ny][nx][1] = 1;
                    q.push({nx, ny, 1, cnt + 1});
                }
                // 벽을 아직 부수지 않았고 지나갈 수 있을 때
                else if (wall == 0 && visited[ny][nx][0] == 0 && map[ny][nx] == 0)
                {
                    visited[ny][nx][0] = 1;
                    q.push({nx, ny, 0, cnt + 1});
                }
                // 벽을 아직 부수지 않았고 벽을 부셔야 지나갈 수 있을 때
                else if (wall == 0 && visited[ny][nx][1] == 0 && map[ny][nx] == 1)
                {
                    visited[ny][nx][1] = 1;
                    q.push({nx, ny, 1, cnt + 1});
                }
            }
        }
    }

    return -1;
}

int main()
{
    string tmp;

    cin >> height >> width;
    for (int i = 0; i < height; i++)
    {
        cin >> tmp;
        for (int j = 0; j < width; j++)
            map[i][j] = tmp[j] - '0';
    }

    cout << BFS();

    return 0;
}