/**
 * @file 04. LCM.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-13 22:18:59
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

int gcd(int a, int b) // 최대공약수
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) // 최소공배수
{
    int tmp;
    tmp = gcd(a, b);
    return a * b / tmp; // 최대공약수를 이용하여 최소공배수 구하기
}

int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }
    return 0;
}