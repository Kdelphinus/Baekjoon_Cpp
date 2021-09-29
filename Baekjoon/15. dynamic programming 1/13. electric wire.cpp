/**
 * @file 13. electric wire.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-07 17:42:16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int remove_wire(int num)
{
    pair<int, int> wire;
    vector<pair<int, int>> wires;
    vector<int> dp(num, 1);
    for (int i = 0; i < num; i++)
    {
        cin >> wire.first >> wire.second;
        wires.push_back(wire);
    }

    stable_sort(wires.begin(), wires.end()); // ������ �������� ����

    for (int i = 1; i < num; i++) // ���ĵ� �����ٿ��� �����ʿ��� LIS�� ����� ���� ���� �������� ���� �� �ִ�
    {
        for (int j = 0; j < i; j++)
        {
            if (wires[i].second > wires[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    return num - *max_element(dp.begin(), dp.end()); // �����ؾ� �� �������� ��
}

int main()
{
    int num;
    cin >> num;
    cout << remove_wire(num);
    return 0;
}