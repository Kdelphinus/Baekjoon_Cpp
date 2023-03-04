/**
 * @file 05. stamp N.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-16 20:43:42
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

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 1; i <= n; i++)
        cout << i << '\n';

    return 0;
}