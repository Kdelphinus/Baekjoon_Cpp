/**
 * @file 03. ATM.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-09 20:22:05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int atm(int num)
{
    vector<int> person(num, 0);
    for (int i = 0; i < num; i++)
        cin >> person[i];

    sort(person.begin(), person.end()); // ���� �ð��� ���� ��� ������� �̴°� ���� ������

    int time = 0;
    for (int i = 0; i < num; i++)
        time += person[i] * (num - i); // �޻���� �ջ���� ���� ������ ��ٷ��� �Ѵ�

    return time;
}

int main()
{
    int num;
    cin >> num;
    cout << atm(num);
    return 0;
}