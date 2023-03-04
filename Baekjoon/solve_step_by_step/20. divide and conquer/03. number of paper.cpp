/**
 * @file 03. number of paper.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 1, 2�� ������ 4������ 9������ �ٲ�
 * @date 2021-08-20 14:32:46
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

int minus_one, zero, plus_one;
vector<vector<int>> paper;

void dc(int num, int x, int y)
{
    if (num == 1)
    {
        if (paper[y][x] == 1)
            plus_one++;
        else if (paper[y][x] == 0)
            zero++;
        else
            minus_one++;
        return;
    }

    int flag = 0;
    for (int i = y; i < y + num; i++)
    {
        if (flag)
            break;
        for (int j = x; j < x + num; j++)
        {
            if (paper[y][x] != paper[i][j])
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag)
    {
        num /= 3;
        dc(num, x, y);                         // ���� ���
        dc(num, x + num, y);                   // �߰� ���
        dc(num, x + (2 * num), y);             // ���� ���
        dc(num, x, y + num);                   // ���� �߰�
        dc(num, x + num, y + num);             // �߾�
        dc(num, x + (2 * num), y + num);       // ���� �߰�
        dc(num, x, y + (2 * num));             // ���� �ϴ�
        dc(num, x + num, y + (2 * num));       // �߰� �ϴ�
        dc(num, x + (2 * num), y + (2 * num)); // ���� �ϴ�
    }
    else
    {
        if (paper[y][x] == 1)
            plus_one++;
        else if (paper[y][x] == 0)
            zero++;
        else
            minus_one++;
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

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
    cout << minus_one << '\n'
         << zero << '\n'
         << plus_one;
    return 0;
}