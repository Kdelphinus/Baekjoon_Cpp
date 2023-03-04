/**
 * @file 08. make to one.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-05 21:41:19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(1000001, 0);

void make_to_one()
{
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 1; i < 1000000; i++)
    {
        // 2�� ���
        if (i * 2 < 1000001 && dp[i * 2] == 0) // ���� ���� ���� ���ٸ�
            dp[i * 2] = dp[i] + 1;
        else if (i * 2 < 1000001) // ���� ���� �����ϸ� �� ���� ������ �ֽ�ȭ
            dp[i * 2] = min(dp[i] + 1, dp[i * 2]);

        // 3�� ���
        if (i * 3 < 1000001 && dp[i * 3] == 0) // ���� ���� ���� ���ٸ�
            dp[i * 3] = dp[i] + 1;
        else if (i * 3 < 1000001) // ���� ���� �����ϸ� �� ���� ������ �ֽ�ȭ
            dp[i * 3] = min(dp[i] + 1, dp[i * 3]);

        // i���� 1 ū ��
        if (dp[i + 1] == 0) // ���� ���� ���� ���ٸ�
            dp[i + 1] = dp[i] + 1;
        else // ���� ���� �����ϸ� �� ���� ������ �ֽ�ȭ
            dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
    }
}

int main()
{
    int num;
    cin >> num;
    make_to_one();
    cout << dp[num];
    return 0;
}