/**
 * @file 04. organic cabbage.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-13 00:23:37
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

int width, height, num;
vector<vector<int>> cabbage(51, vector<int>(51, 0));

void DFS(int x, int y)
{
    cabbage[y][x] = 0;

    if (x - 1 >= 0 && cabbage[y][x - 1] == 1)
        DFS(x - 1, y);
    if (y - 1 >= 0 && cabbage[y - 1][x] == 1)
        DFS(x, y - 1);
    if (x + 1 < width && cabbage[y][x + 1] == 1)
        DFS(x + 1, y);
    if (y + 1 < height && cabbage[y + 1][x] == 1)
        DFS(x, y + 1);
}

int main()
{
    int test;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        int tmp_x, tmp_y, earthworms = 0;
        cin >> width >> height >> num;

        // 배추 위치 저장
        for (int j = 0; j < num; j++)
        {
            cin >> tmp_x >> tmp_y;
            cabbage[tmp_y][tmp_x] = 1;
        }

        // 배추가 있는 곳을 DFS로 탐색
        for (int h = 0; h < height; h++)
        {
            for (int w = 0; w < width; w++)
            {
                if (cabbage[h][w] == 1)
                {
                    DFS(w, h);
                    earthworms++;
                }
            }
        }
        cout << earthworms << '\n';
    }

    return 0;
}