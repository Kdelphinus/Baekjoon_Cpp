/**
 * @file 09. sort by age.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief sort와 stable_sort의 차이
 * @date 2021-07-28 15:44:44
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) // 가입순으로 정렬하게 만드는 함수
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

    stable_sort(arr.begin(), arr.end(), compare); // 크기가 같은 원소는 상대적 위치가 바뀌지 않도록 한다
    for (int i = 0; i < num; i++)
        cout << arr[i].first << " " << arr[i].second << '\n';
    return 0;
}