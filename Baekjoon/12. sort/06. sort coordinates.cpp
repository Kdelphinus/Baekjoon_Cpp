/**
 * @file 06. sort coordinates.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief
 * @date 2021-07-27 00:01:47
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2, 0)); // n칸 짜리 vector 안에 2칸 짜리 vector를 만들고 값은 0으로 초기화
    for (int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1];

    sort(arr.begin(), arr.end()); // vector 정렬

    for (int i = 0; i < n; i++)
        cout << arr[i][0] << " " << arr[i][1] << "\n";
    return 0;
}