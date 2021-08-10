/**
 * @file 03. GCD and LCM.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-10 21:47:12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int lcd(int x, int y) // gcd�� �ٽ� ���ϱ⿡ ��ȿ�����̳� lcd�� gcd�� ���踦 ��Ÿ���� ���Ͽ� ��
{
    return x * y / gcd(x, y);
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << '\n';
    cout << lcd(x, y);
    return 0;
}