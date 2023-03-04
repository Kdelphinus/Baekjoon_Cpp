/**
 * @file 09. building bridges.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 이항계수(right, left)가 확률의 답
 * @date 2021-08-15 22:47:32
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

long long building(int left, int right)
{
    vector<vector<long long>> dp(right + 1, vector<long long>(left + 1, 1));
    for (int i = 1; i <= right; i++)
    {
        for (int j = 0; j <= left; j++)
        {
            if (i > j && j > 0)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[right][left];
}

int main()
{
    int test;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        int left, right;
        cin >> left >> right;
        cout << building(left, right) << '\n';
    }

    return 0;
}