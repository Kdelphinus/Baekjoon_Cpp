/**
 * @file 07. climb stairs.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-05 21:22:26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> stairs;

int dynamic_programming(int num)
{
    if (num == 1) // ����� �ϳ��� ��
        return stairs[0];

    if (num == 2) // ����� �� �� �϶�
        return stairs[0] + stairs[1];

    // �ʱⰪ ����
    int dp[num] = {0}; // �� ��ġ�� ����� ��, �ְ� ������ �����ϴ� �迭
    dp[0] = stairs[0];
    dp[1] = dp[0] + stairs[1];
    dp[2] = stairs[2] + max(stairs[0], stairs[1]);

    // ���� ����� ��� �Ͱ� ���� ����� ��� �� �� �� ū ������ ��� ������ ����
    for (int i = 3; i < num; i++)
        dp[i] = stairs[i] + max(stairs[i - 1] + dp[i - 3], dp[i - 2]);

    return dp[num - 1]; // ������ ����� ������ ��ƾ� �Ѵ�
}

int main()
{
    int num, tmp;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        stairs.push_back(tmp);
    }

    cout << dynamic_programming(num);

    return 0;
}