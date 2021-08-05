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

vector<vector<long long>> dp(101, vector<long long>(10, 0));
long long mod = 1000000000;

long long number_of_stairs(int num)
{
    for (int i = 1; i <= 9; i++) // 한 자리 숫자들은 모두 계단 수이다
        dp[1][i] = 1;

    for (int i = 2; i <= num; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0) // 끝자리가 0이면 1밖에 오지 못한다
                dp[i][j] = dp[i - 1][j + 1];
            else if (j == 9) // 끝자리가 9이면 8밖에 오지 못한다
                dp[i][j] = dp[i - 1][j - 1];
            else // 나머지 숫자들은 두 개의 숫자가 올 수 있다
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
        }
    }

    long long sum = 0;
    for (int i = 0; i <= 9; i++)
        sum += dp[num][i] % mod;

    return sum % mod; // 벡터의 합을 리턴하는 함수
}

int main()
{
    int num;
    cin >> num;
    cout << number_of_stairs(num);
    return 0;
}