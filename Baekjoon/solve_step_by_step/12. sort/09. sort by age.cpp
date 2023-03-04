/**
 * @file 09. sort by age.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief sort�� stable_sort�� ����
 * @date 2021-07-28 15:44:44
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) // ���Լ����� �����ϰ� ����� �Լ�
{
    return a.first < b.first;
}

int main()
{
    int num;
    cin >> num;
    pair<int, string> tmp;
    vector<pair<int, string>> arr;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }

    stable_sort(arr.begin(), arr.end(), compare); // ũ�Ⱑ ���� ���Ҵ� ����� ��ġ�� �ٲ��� �ʵ��� �Ѵ�
    for (int i = 0; i < num; i++)
        cout << arr[i].first << " " << arr[i].second << '\n';
    return 0;
}