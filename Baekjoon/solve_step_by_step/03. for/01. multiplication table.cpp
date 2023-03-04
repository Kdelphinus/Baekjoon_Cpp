/**
 * @file 01. multiplication table.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-16 20:31:30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i < 10; i++)
        cout << n << " * " << i << " = " << n * i << endl;

    return 0;
}