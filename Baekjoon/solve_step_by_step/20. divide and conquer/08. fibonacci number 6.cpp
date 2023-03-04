/**
 * @file 08. fibonacci number 6.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 7번 문제와 유사
 * @date 2021-08-20 18:01:31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/* 
[[1, 1], [1, 0]] ^ n = [[fib(n + 1), fib(n)], [fib(n), fib(n - 1)]]
*/

#include <iostream>
#include <vector>

using namespace std;

long long mod = 1000000007;
vector<vector<long long>> origin{{1, 1}, {1, 0}};
vector<vector<long long>> fibonacci{{1, 1}, {1, 0}};

void square() // 행렬을 제곱하는 함수
{
    vector<vector<long long>> tmp(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            long long num = 0;
            for (int k = 0; k < 2; k++)
                num += (fibonacci[i][k] * fibonacci[k][j]) % mod;
            tmp[i][j] = num % mod;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            fibonacci[i][j] = tmp[i][j] % mod;
    }
}

void fib(long long num)
{
    if (num == 1)
        return;

    fib(num / 2);
    square();

    if (num % 2)
    {
        vector<vector<long long>> tmp(2, vector<long long>(2, 0));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                long long num = 0;
                for (int k = 0; k < 2; k++)
                    num += (fibonacci[i][k] * origin[k][j]) % mod;
                tmp[i][j] = num % mod;
            }
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                fibonacci[i][j] = tmp[i][j] % mod;
        }
    }
    return;
}

int main()
{
    long long num;
    cin >> num;
    fib(num);
    cout << fibonacci[0][1] % mod;
    return 0;
}