/**
 * @file 09. Elementary arithmetic.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-14 23:11:15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    cout << a + b << endl
         << a - b << endl
         << a * b << endl
         << a / b << endl
         << a % b;

    return 0;
}