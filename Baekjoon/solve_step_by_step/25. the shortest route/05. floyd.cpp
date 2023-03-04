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
    // prices 벡터 초기화
    for (int i = 1; i <= city; i++)
    {
        for (int j = 1; j <= city; j++)
        {
            if (i == j) // 같은 도시는 비용이 들지 않는다
                prices[i][j] = 0;
            else // 다른 도시는 우선 직항 가격으로 초기화한다
                prices[i][j] = route[i][j];
        }
    }

    for (int wayp = 1; wayp <= city; wayp++) // 들릴 지점
    {
        for (int start = 1; start <= city; start++) // 출발 지점
        {
            for (int arrive = 1; arrive <= city; arrive++) // 도착 지점
            {
                // 현재 비용보다 들릴 지점을 들려서 가는게 더 저렴할 경우
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
            if (prices[i][j] >= 10000001) // i에서 j로 갈 수 없는 경우
                cout << 0 << ' ';
            else // 갈 수 있는 경우
                cout << prices[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}