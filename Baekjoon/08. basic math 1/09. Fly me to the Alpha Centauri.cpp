/**
 * @file 09. Fly me to the Alpha Centauri.cpp3
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief �ؼ�����: https://aorica.tistory.com/126
 * @date 2021-07-24 17:49:58
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int j = 0; j < T; j++)
    {
        long double x, y, d, i = 1;
        cin >> x >> y;
        d = y - x;
        while (1)
        {
            if (i * i > d)
                break;
            i++;
        }

        if (pow(i - 1, 2) == y - x) // �������� ��
            cout << 2 * i - 3 << '\n';
        else if ((pow(i, 2) + pow(i - 1, 2)) / 2 >= y - x) // �߰������� ���� ��
            cout << 2 * (i - 1) << '\n';
        else // �߰������� Ŭ ��
            cout << 2 * (i - 1) + 1 << '\n';
    }
}