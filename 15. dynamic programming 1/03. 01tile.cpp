/**
 * @file 03. 01tile.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 가짓수가 피보나치 수와 동일
 * @date 2021-08-03 23:38:56
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;
int mod = 15746;

int tile(int num)
{
    int dp[num + 1] = {0};
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= num; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;

    return dp[num];
}

int main()
{
    int num;
    cin >> num;
    cout << tile(num);

    return 0;
}