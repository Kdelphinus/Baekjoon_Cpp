/**
 * @file 09. easy number of stairs.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-05 22:55:39
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<vector<int>> dp(101, vector<int>(10, 0));
int mod = 1000000000;

int number_of_stairs(int num)
{
    for (int i = 1; i <= 9; i++) // �� �ڸ� ���ڵ��� ��� ��� ���̴�
        dp[1][i] = 1;

    for (int i = 2; i <= num; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0) // ���ڸ��� 0�̸� 1�ۿ� ���� ���Ѵ�
                dp[i][j] = dp[i - 1][j + 1];
            else if (j == 9) // ���ڸ��� 9�̸� 8�ۿ� ���� ���Ѵ�
                dp[i][j] = dp[i - 1][j - 1];
            else // ������ ���ڵ��� �� ���� ���ڰ� �� �� �ִ�
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
        }
    }

    return accumulate(dp[num].begin(), dp[num].end(), 0) % mod; // ������ ���� �����ϴ� �Լ�
}

int main()
{
    int num;
    cin >> num;
    cout << number_of_stairs(num);
    return 0;
}