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

int width, height;                                        // x��, y��
int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // �׹���
int maze[101][101];                                       // �̷�
queue<pair<int, int>> q;                                  // BFS�� ���� ť

void BFS()
{
    q.push(make_pair(0, 0)); // ���� ����
    pair<int, int> now;      // ���� ��ġ�� ������ pair
    int nx, ny;

    while (!q.empty())
    {
        now = q.front(); // ���� ��ġ
        q.pop();         // ���� ��ġ�� queue���� ���ش�

        for (int i = 0; i < 4; i++)
        {
            nx = now.first + direction[i][0];  // �̵��� ��ġ�� x��ǥ
            ny = now.second + direction[i][1]; // �̵��� ��ġ�� y��ǥ

            if (0 <= nx < width && 0 <= ny < height && maze[ny][nx] == 1) // �� �� �ִٸ�
            {
                q.push(make_pair(nx, ny));                      // Ž�� ��ġ �߰�
                maze[ny][nx] = maze[now.second][now.first] + 1; // ���� ��ġ�� �ִ� �Ÿ����� 1�߰�
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