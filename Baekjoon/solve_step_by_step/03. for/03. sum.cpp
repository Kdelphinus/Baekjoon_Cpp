/**
 * @file 03. sum.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-16 20:36:12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
        sum += i;

    cout << sum;
    return 0;
}