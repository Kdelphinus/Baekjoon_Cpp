/**
 * @file 01. compare two numbers.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-16 18:52:11
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

    if (a > b)
        cout << ">";
    else if (a < b)
        cout << "<";
    else
        cout << "==";
    return 0;
}