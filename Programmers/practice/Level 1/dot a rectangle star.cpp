/**
 * @file dot a rectangle star.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-28 01:34:13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
            cout << '*';
        cout << '\n';
    }
    return 0;
}