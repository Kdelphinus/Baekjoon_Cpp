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
int width, vertical, height; // ����, ����, ����
int boxes[101][101][101];    // �ڽ���
int zeros, ones;             // �ʱ� �� ���� �丶���� ��, �ð��� ������ ���� �丶���� ��
int cnt, days;               // �� �� ���� �丶���� ��, �� ���� ��¥
queue<tuple<int, int, int>> q;

int BFS()
{
    tuple<int, int, int> tmp;
    int day_tomato = q.size(); // ���� Ȯ���� �丶���� ��
    int nx, ny, nz;
    while (!q.empty())
    {
        if (cnt == day_tomato) // ���� Ȯ���� �丶�並 ��� Ȯ���ߴٸ�
        {
            days++;                // ��¥ ����
            cnt = 0;               // �ʱ�ȭ
            day_tomato = q.size(); // �ֽ�ȭ
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
                if (boxes[h][v][w] == 0) // �ʱ� ���� ���� �丶���� ��
                    zeros++;
                else if (boxes[h][v][w] == 1) // ���� ��¥�� Ȯ���ؾ� �� �丶���
                    q.push(make_tuple(h, v, w));
            }
        }
    }

    cout << BFS();

    return 0;
}