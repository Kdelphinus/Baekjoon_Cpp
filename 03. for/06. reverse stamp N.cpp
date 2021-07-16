/**
 * @file 06. reverse stamp N.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-16 20:47:29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main()
{
    int n;

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = n; i > 0; i--)
        cout << i << '\n';
    return 0;
}