/**
 * @file 07. A+B - 7.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-16 20:50:16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main()
{
    int test, a, b;

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> test;
    for (int i = 1; i <= test; i++)
    {
        cin >> a >> b;
        cout << "Case #" << i << ": " << a + b << '\n';
    }
    return 0;
}