/**
 * @file 05. gas station.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-10 11:32:09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

long long min_price(int num)
{
    vector<long long> dist(num - 1, 0);
    vector<long long> price(num, 0);

    for (int i = 0; i < num - 1; i++) // �Ÿ�
        cin >> dist[i];

    for (int i = 0; i < num; i++) // ����
        cin >> price[i];

    long long tmp = price[0], total_dist = dist[0]; // ó�� �����ҿ��� ������ �����ؾ� �Ѵ�
    long long anw = 0;

    for (int i = 1; i < num - 1; i++)
    {
        if (tmp > price[i]) // ���� ���� �����Ұ� ���� �����Һ��� �δٸ�
        {
            anw += tmp * total_dist; // ���ݱ��� �Ÿ���ŭ�� ���� �����ҿ��� �����ϰ�
            tmp = price[i];          // ������ ���� �����ҷ� �ٲٰ�
            total_dist = dist[i];    // �Ÿ��� ���� �����Һ��� �ٽ� �����Ѵ�
        }
        else                       // ���� �����Ұ� ���� �����Һ��� ��δٸ�
            total_dist += dist[i]; // ���� �����ҿ��� ������ �Ÿ��� �߰��Ѵ�
    }
    anw += tmp * total_dist; // ������ �����ҿ� �����ϵ��� �����Ѵ�

    return anw;
}

int main()
{
    int num;
    cin >> num;
    cout << min_price(num);
    return 0;
}