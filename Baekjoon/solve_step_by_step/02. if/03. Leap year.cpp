/**
 * @file 03. Leap year.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-16 18:57:55
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main()
{
    int year;
    cin >> year;

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        cout << 1;
    else
        cout << 0;
    return 0;
}