/**
 * @file 04. multiplication.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-20 14:50:26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

long long mod;

long long multiplication(long long num, long long power)
{
    if (power == 1) // 1¹ø °öÇÏ¸é ÀÚ±â ÀÚ½Å
        return num % mod;

    long long tmp = multiplication(num, power / 2) % mod;
    if (power % 2) // È¦¼ö¹ø °öÇÒ ¶§
        return ((tmp * tmp) % mod * num) % mod;
    else // Â¦¼ö¹ø °öÇÒ ¶§
        return (tmp * tmp) % mod;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long num, power;
    cin >> num >> power >> mod;
    cout << multiplication(num, power);
    return 0;
}