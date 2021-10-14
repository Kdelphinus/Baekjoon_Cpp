/**
 * @file 07. tomato 3d.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief
 * @date 2021-10-14 18:31:45
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int direction[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int width, vertical, height; // 가로, 세로, 높이
int boxes[101][101][101];    // 박스들
int zeros, ones;             // 초기 안 익은 토마토의 수, 시간이 지나며 익은 토마토의 수
int cnt, days;               // 그 날 익은 토마토의 수, 총 지난 날짜
queue<tuple<int, int, int>> q;

int BFS()
{
    tuple<int, int, int> tmp;
    int day_tomato = q.size(); // 당일 확인할 토마토의 수
    int nx, ny, nz;
    while (!q.empty())
    {
        if (cnt == day_tomato) // 당일 확인할 토마토를 모두 확인했다면
        {
            days++;                // 날짜 지남
            cnt = 0;               // 초기화
            day_tomato = q.size(); // 최신화
        }

        tmp = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            nz = get<0>(tmp) + direction[i][0];
            ny = get<1>(tmp) + direction[i][1];
            nx = get<2>(tmp) + direction[i][2];

            if (0 <= nz && nz < height && 0 <= ny && ny < vertical && 0 <= nx && nx < width && boxes[nz][ny][nx] == 0)
            {
                boxes[nz][ny][nx] = 1;
                ones++;
                q.push(make_tuple(nz, ny, nx));
            }
        }
        cnt++;
    }

    if (zeros == ones)
        return days;
    return -1;
}

int main()
{
    cin >> width >> vertical >> height;
    for (int h = 0; h < height; h++)
    {
        for (int v = 0; v < vertical; v++)
        {
            for (int w = 0; w < width; w++)
            {
                cin >> boxes[h][v][w];
                if (boxes[h][v][w] == 0) // 초기 익지 않은 토마토의 수
                    zeros++;
                else if (boxes[h][v][w] == 1) // 시작 날짜에 확인해야 할 토마토들
                    q.push(make_tuple(h, v, w));
            }
        }
    }

    cout << BFS();

    return 0;
}