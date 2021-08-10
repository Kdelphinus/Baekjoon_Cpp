/**
 * @file 01. multiples and divisors.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-10 21:33:21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

void check(int num1, int num2)
{
    if (num1 > num2 && num1 % num2 == 0)
        cout << "multiple\n";
    else if (num1 < num2 && num2 % num1 == 0)
        cout << "factor\n";
    else
        cout << "neither\n";
}

int main()
{
    int num1, num2;
    while (1)
    {
        cin >> num1 >> num2;
        if (num1 == 0 && num2 == 0)
            break;
        check(num1, num2);
    }
    return 0;
}