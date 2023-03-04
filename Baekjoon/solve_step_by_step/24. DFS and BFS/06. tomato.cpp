/**
 * @file 06. tomato.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-13 20:19:25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <queue>
using namespace std;

int width, height, day;
int tomatos, cnt; // 그 날 익은 토마토의 수, 현재 확인한 토마토의 수
int zeros, ones;  // 익기 전 토마토 수, 익은 토마토 수(처음부터 익은 토마토는 제외)
int box[1001][1001];
int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 방향
queue<pair<int, int>> q;

int BFS()
{
    pair<int, int> now;
    while (!q.empty())
    {
        if (cnt == tomatos) // 당일 익은 토마토를 모두 확인했다면
        {
            tomatos = q.size(); // 당일을 통해 익은 토마토 수 저장
            cnt = 0;            // cnt 초기화
            day++;              // 하루 지남
        }

        now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = now.second + direction[i][1];
            int ny = now.first + direction[i][0];

            if (0 <= nx && nx < width && 0 <= ny && ny < height && box[ny][nx] == 0)
            {
                box[ny][nx] = 1;
                q.push(make_pair(ny, nx));
                ones++; // 익은 토마토 추가
            }
        }
        cnt++;
    }

    if (zeros == ones) // 모두 익었다면
        return day;    // 날짜 리턴
    else               // 모두 익지 않았다면
        return -1;     // -1 리턴
}

int main()
{
    pair<int, int> tmp;
    cin >> width >> height;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1) // 익은 토마토 위치 저장
                q.push(make_pair(i, j));
            else if (box[i][j] == 0) // 안 익은 토마토 개수 저장
                zeros++;
        }
    }

    tomatos = q.size(); // 0일 때 익은 토마토 개수
    cout << BFS();

    return 0;
}