/**
 * @file 05. exploring the maze.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-13 02:05:26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <queue>
using namespace std;

int width, height;                                        // x축, y축
int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 네방향
int maze[101][101];                                       // 미로
queue<pair<int, int>> q;                                  // BFS를 위한 큐

void BFS()
{
    q.push(make_pair(0, 0)); // 시작 지점
    pair<int, int> now;      // 현재 위치를 저장할 pair
    int nx, ny;

    while (!q.empty())
    {
        now = q.front(); // 현재 위치
        q.pop();         // 현재 위치는 queue에서 빼준다

        for (int i = 0; i < 4; i++)
        {
            nx = now.first + direction[i][0];  // 이동할 위치의 x좌표
            ny = now.second + direction[i][1]; // 이동할 위치의 y좌표

            if (0 <= nx < width && 0 <= ny < height && maze[ny][nx] == 1) // 갈 수 있다면
            {
                q.push(make_pair(nx, ny));                      // 탐색 위치 추가
                maze[ny][nx] = maze[now.second][now.first] + 1; // 이전 위치의 최단 거리에서 1추가
            }
        }
    }
}

int main()
{
    string tmp;
    cin >> height >> width;
    for (int i = 0; i < height; i++)
    {
        cin >> tmp;
        for (int j = 0; j < width; j++)
            maze[i][j] = tmp[j] - '0';
    }

    BFS();
    cout << maze[height - 1][width - 1];

    return 0;
}