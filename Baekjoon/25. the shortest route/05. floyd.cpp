/**
 * @file 05. floyd.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-27 23:15:28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

int city, bus;
vector<vector<int>> route(101, vector<int>(101, 10000001));
vector<vector<int>> prices(101, vector<int>(101, 10000001));

void floyd()
{
    // prices ���� �ʱ�ȭ
    for (int i = 1; i <= city; i++)
    {
        for (int j = 1; j <= city; j++)
        {
            if (i == j) // ���� ���ô� ����� ���� �ʴ´�
                prices[i][j] = 0;
            else // �ٸ� ���ô� �켱 ���� �������� �ʱ�ȭ�Ѵ�
                prices[i][j] = route[i][j];
        }
    }

    for (int wayp = 1; wayp <= city; wayp++) // �鸱 ����
    {
        for (int start = 1; start <= city; start++) // ��� ����
        {
            for (int arrive = 1; arrive <= city; arrive++) // ���� ����
            {
                // ���� ��뺸�� �鸱 ������ ����� ���°� �� ������ ���
                if (prices[start][arrive] > prices[start][wayp] + prices[wayp][arrive])
                    prices[start][arrive] = prices[start][wayp] + prices[wayp][arrive];
            }
        }
    }
}

int main()
{
    cin >> city >> bus;
    int start, arrive, price;
    for (int i = 0; i < bus; i++)
    {
        cin >> start >> arrive >> price;
        route[start][arrive] = min(price, route[start][arrive]);
    }

    floyd();

    for (int i = 1; i <= city; i++)
    {
        for (int j = 1; j <= city; j++)
        {
            if (prices[i][j] >= 10000001) // i���� j�� �� �� ���� ���
                cout << 0 << ' ';
            else // �� �� �ִ� ���
                cout << prices[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}