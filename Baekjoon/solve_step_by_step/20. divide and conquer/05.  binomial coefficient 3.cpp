/* 
이항계수(n, k) = n! / (k!(n - k)!)

페르마의 소정리: 
((p - 1)! a^(p - 1)) % p = (p - 1)! % p
(a^(p - 1)) % p = 1 % p

(a^p) % p = a % p
(a^(p - 2)) % p = (1 / a) % p 
*/

/**
 * @file 05.  binomial coefficient 3.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 페르마의 소정리 이용
 * @date 2021-08-20 15:15:30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

long long mod = 1000000007;
vector<long long> fact(1, 1);

long long power(long long num, long long y)
{
    if (y == 1)
        return num % mod;

    long long tmp = power(num, y / 2);
    if (y % 2)
        return (((tmp * tmp) % mod) * num) % mod;
    else
        return (tmp * tmp) % mod;
}

long long factorial(int num)
{
    if (fact.size() <= num)
    {
        for (int i = fact.size(); i <= num; i++)
            fact.push_back((fact[i - 1] * i) % mod);
    }

    return fact[num];
}

long long bc(long long n, long long k)
{
    long long denominator, numerator;
    numerator = factorial(n);
    denominator = factorial(k) * factorial(n - k) % mod;

    // (numerator^(mod - 2)) % mod = (1 / numerator) % mod
    return numerator * (power(denominator, mod - 2) % mod) % mod;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long n, k;
    cin >> n >> k;
    cout << bc(n, k);
    return 0;
}