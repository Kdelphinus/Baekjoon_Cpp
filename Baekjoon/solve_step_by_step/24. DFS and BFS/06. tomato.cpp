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
int tomatos, cnt; // �� �� ���� �丶���� ��, ���� Ȯ���� �丶���� ��
int zeros, ones;  // �ͱ� �� �丶�� ��, ���� �丶�� ��(ó������ ���� �丶��� ����)
int box[1001][1001];
int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // ����
queue<pair<int, int>> q;

int BFS()
{
    pair<int, int> now;
    while (!q.empty())
    {
        if (cnt == tomatos) // ���� ���� �丶�並 ��� Ȯ���ߴٸ�
        {
            tomatos = q.size(); // ������ ���� ���� �丶�� �� ����
            cnt = 0;            // cnt �ʱ�ȭ
            day++;              // �Ϸ� ����
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
                ones++; // ���� �丶�� �߰�
            }
        }
        cnt++;
    }

    if (zeros == ones) // ��� �;��ٸ�
        return day;    // ��¥ ����
    else               // ��� ���� �ʾҴٸ�
        return -1;     // -1 ����
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
            if (box[i][j] == 1) // ���� �丶�� ��ġ ����
                q.push(make_pair(i, j));
            else if (box[i][j] == 0) // �� ���� �丶�� ���� ����
                zeros++;
        }
    }

    tomatos = q.size(); // 0�� �� ���� �丶�� ����
    cout << BFS();

    return 0;
}