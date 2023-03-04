/**
 * @file 05. install routers.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-03 19:01:42
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist;
vector<int> house;

void binary_search(int house_num, int router_num, int min_dist, int max_dist)
{
    if (min_dist > max_dist) // 종결조건
        return;

    int mid = (min_dist + max_dist) / 2; // 설치할 공유기 사이의 거리
    int installed_routers = 1;           // 설치한 공유기 수
    int lastest_installed = house[0];    // 가장 마지막에 설치한 공유기 위치

    for (int i = 1; i < house_num; i++)
    {
        if (lastest_installed + mid <= house[i]) // 마지막으로 설치한 지점에서 mid떨어진 지점이 다음 집을 넘어가지 않으면
        {
            installed_routers++;          // 공유기를 설치하고
            lastest_installed = house[i]; // 최신화
        }
    }

    if (installed_routers >= router_num) // 원하는 개수만큼 공유기를 설치했다면
    {
        dist = mid;                                              // 지금 설치한 간격을 저장
        binary_search(house_num, router_num, mid + 1, max_dist); // 더 긴 거리로 가능한지 확인
    }
    else                                                         // 원하는 개수만큼 설치하지 못했다면
        binary_search(house_num, router_num, min_dist, mid - 1); // 더 짧은 거리로 가능한지 확인
}

int main()
{
    int house_num, router_num, tmp;
    cin >> house_num >> router_num;

    for (int i = 0; i < house_num; i++)
    {
        cin >> tmp;
        house.push_back(tmp);
    }
    sort(house.begin(), house.end()); // 이진 탐색은 정렬이 되어있어야 한다
    binary_search(house_num, router_num, 1, house[house_num - 1] - house[0]);
    cout << dist;

    return 0;
}