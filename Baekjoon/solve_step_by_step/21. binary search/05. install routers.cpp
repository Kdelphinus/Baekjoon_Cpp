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
    if (min_dist > max_dist) // ��������
        return;

    int mid = (min_dist + max_dist) / 2; // ��ġ�� ������ ������ �Ÿ�
    int installed_routers = 1;           // ��ġ�� ������ ��
    int lastest_installed = house[0];    // ���� �������� ��ġ�� ������ ��ġ

    for (int i = 1; i < house_num; i++)
    {
        if (lastest_installed + mid <= house[i]) // ���������� ��ġ�� �������� mid������ ������ ���� ���� �Ѿ�� ������
        {
            installed_routers++;          // �����⸦ ��ġ�ϰ�
            lastest_installed = house[i]; // �ֽ�ȭ
        }
    }

    if (installed_routers >= router_num) // ���ϴ� ������ŭ �����⸦ ��ġ�ߴٸ�
    {
        dist = mid;                                              // ���� ��ġ�� ������ ����
        binary_search(house_num, router_num, mid + 1, max_dist); // �� �� �Ÿ��� �������� Ȯ��
    }
    else                                                         // ���ϴ� ������ŭ ��ġ���� ���ߴٸ�
        binary_search(house_num, router_num, min_dist, mid - 1); // �� ª�� �Ÿ��� �������� Ȯ��
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
    sort(house.begin(), house.end()); // ���� Ž���� ������ �Ǿ��־�� �Ѵ�
    binary_search(house_num, router_num, 1, house[house_num - 1] - house[0]);
    cout << dist;

    return 0;
}