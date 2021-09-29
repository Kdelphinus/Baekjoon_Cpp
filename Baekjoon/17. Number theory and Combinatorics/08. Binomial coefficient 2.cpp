/**
 * @file 08. Binomial coefficient 2.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 이항계수의 성질 이용
 * @date 2021-08-13 23:05:39
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

int mod = 10007;

long long bc(int a, int b) // 이항 계수를 구하는 함수
{
    vector<vector<long long>> dp(a + 1, vector<long long>(b + 1, 1)); // 기본값은 1(분모에 0!이 하나라도 들어가면 1이 됨)
    for (int i = 1; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i > j && j > 0)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod; // 이항계수의 성질
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