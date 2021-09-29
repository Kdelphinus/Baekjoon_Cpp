/**
 * @file 06. ring.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-13 22:42:48
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) // �ִ������� ���ϴ� �Լ�
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void ring(int num)
{
    vector<int> arr(num, 0);
    for (int i = 0; i < num; i++)
        cin >> arr[i];

    int tmp, standard = arr[0]; // ������ �Ǵ� ��
    for (int i = 1; i < num; i++)
    {
        tmp = gcd(arr[i], standard);                           // �� ���� �ִ������� ���Ͽ�
        cout << standard / tmp << "/" << arr[i] / tmp << "\n"; // ������ �ȴ�
    }
}

int main()
{
    int num;
    cin >> num;
    ring(num);
    return 0;
}