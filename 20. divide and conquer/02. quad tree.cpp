/**
 * @file 02. quad tree.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-19 23:03:03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> video;

void compression(int num, int x, int y)
{
    if (num == 1) // ���� ũ�Ⱑ 1�̸� ���� �ٷ� �Ϸ�
    {
        cout << video[y][x];
        return;
    }

    int flag = 0;
    for (int i = y; i < y + num; i++) // �������� �ٸ� ���� ������ �ٷ� ����
    {
        if (flag)
            break;
        for (int j = x; j < x + num; j++)
        {
            if (video[y][x] != video[i][j])
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag) // �ٸ� ���� �־��ٸ�
    {
        cout << "(";                        // ���� ����
        num /= 2;                           // ũ�⸦ �ΰ��� ������
        compression(num, x, y);             // ���� ���
        compression(num, x + num, y);       // ���� ���
        compression(num, x, y + num);       // ���� �ϴ�
        compression(num, x + num, y + num); // ���� �ϴ�
        cout << ")";                        // ���� ����
    }
    else                     // �ٸ� ���� ���ٸ�
        cout << video[y][x]; // ���������� ����
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num;
    cin >> num;
    for (int i = 0; i < num; i++) // �پ��ִ� ���ڴ� �� ���� �޾ƹ����⿡ ���ڿ��� �޾� ���� ����
    {
        string tmp;
        vector<int> tmp_vec(num, 0);
        cin >> tmp;
        for (int j = 0; j < num; j++)
            tmp_vec[j] = tmp[j] - '0';
        video.push_back(tmp_vec);
    }
    compression(num, 0, 0);
    return 0;
}