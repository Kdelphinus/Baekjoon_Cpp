/**
 * @file 01. create colored paper.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-19 22:40:26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

int white, blue;
vector<vector<int>> paper;

void dc(int num, int x, int y)
{
    int flag = 0, standard = paper[y][x];

    if (num == 1) // ������ ũ�Ⱑ 1�̸� ������ �ٷ� �ϼ�
    {
        if (standard)
            blue++;
        else
            white++;
        return;
    }

    for (int i = y; i < y + num; i++) // ���� ĭ�� �ٸ� ĭ�� ���Ѵ�
    {
        if (flag)
            break;
        for (int j = x; j < x + num; j++)
        {
            if (standard != paper[i][j]) // ���� ���� ĭ�� �ٸ� ĭ�� ���� �ٸ���
            {
                flag = 1; // ǥ�� �� ����
                break;
            }
        }
    }

    if (flag) // �ٸ� ���� �־�����
    {
        num /= 2;                  // ũ�⸦ �������� ������
        dc(num, x, y);             // ������� Ȯ��
        dc(num, x, y + num);       // �����ϴ� Ȯ��
        dc(num, x + num, y);       // ������� Ȯ��
        dc(num, x + num, y + num); // �����ϴ� Ȯ��
    }
    else // �ٸ� ���� ������ ������ �߰�
    {
        if (standard)
            blue++;
        else
            white++;
    }
}

int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        vector<int> tmp(num, 0);
        for (int j = 0; j < num; j++)
            cin >> tmp[j];
        paper.push_back(tmp);
    }
    dc(num, 0, 0);
    cout << white << '\n'
         << blue;
    return 0;
}