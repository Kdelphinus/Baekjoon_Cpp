/**
 * @file 08.A divide B.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-14 23:08:05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;

    cout.precision(15); // 최대 15자리만큼 출력
    cout << a / b;
    return 0;
}