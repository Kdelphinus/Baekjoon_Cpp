/**
 * @file 11. multiplication.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-14 23:26:32
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

    cout << a * (b % 10) << endl
         << a * ((b / 10) % 10) << endl
         << a * (b / 100) << endl
         << a * b;
    return 0;
}