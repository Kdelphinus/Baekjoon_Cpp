/**
 * @file 02. A+B - 3.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-16 20:34:30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main()
{
    int test, a, b;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}