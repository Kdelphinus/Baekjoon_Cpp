/**
 * @file 10. remainder.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-14 23:22:32
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + b) % c << endl
         << ((a % c) + (b % c)) % c << endl
         << (a * b) % c << endl
         << ((a % c) * (b % c)) % c;
    return 0;
}