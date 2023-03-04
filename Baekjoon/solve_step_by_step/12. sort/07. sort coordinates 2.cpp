/**
 * @file 07. sort coordinates 2.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-27 00:09:11
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

    int num;
    cin >> num;

    vector<vector<int>> arr(num, vector<int>(2, 0));
    for (int i = 0; i < num; i++)
        cin >> arr[i][1] >> arr[i][0]; // y를 우선순위로 하기 위해 y를 0번째에 저장

    sort(arr.begin(), arr.end());
    for (int i = 0; i < num; i++)
        cout << arr[i][1] << " " << arr[i][0] << "\n";

    return 0;
}