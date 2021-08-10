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

    for (int i = 0; i < num - 1; i++) // 거리
        cin >> dist[i];

    for (int i = 0; i < num; i++) // 가격
        cin >> price[i];

    long long tmp = price[0], total_dist = dist[0]; // 처음 주유소에선 무조건 주유해야 한다
    long long anw = 0;

    for (int i = 1; i < num - 1; i++)
    {
        if (tmp > price[i]) // 만약 다음 주유소가 이전 주유소보다 싸다면
        {
            anw += tmp * total_dist; // 지금까지 거리만큼만 이전 주유소에서 주유하고
            tmp = price[i];          // 가격을 현재 주유소로 바꾸고
            total_dist = dist[i];    // 거리도 현재 주유소부터 다시 측정한다
        }
        else                       // 다음 주유소가 이전 주유소보다 비싸다면
            total_dist += dist[i]; // 이전 주유소에서 주유할 거리를 추가한다
    }
    anw += tmp * total_dist; // 마지막 주유소에 도착하도록 주유한다

    return anw;
}

int main()
{
    int num;
    cin >> num;
    cout << min_price(num);
    return 0;
}