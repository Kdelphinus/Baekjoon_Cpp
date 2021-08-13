/**
 * @file 08. Binomial coefficient 2.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief ���װ���� ���� �̿�
 * @date 2021-08-13 23:05:39
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

int mod = 10007;

long long bc(int a, int b) // ���� ����� ���ϴ� �Լ�
{
    vector<vector<long long>> dp(a + 1, vector<long long>(b + 1, 1)); // �⺻���� 1(�и� 0!�� �ϳ��� ���� 1�� ��)
    for (int i = 1; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i > j && j > 0)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod; // ���װ���� ����
        }
    }

    return dp[a][b];
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << bc(a, b);
    return 0;
}