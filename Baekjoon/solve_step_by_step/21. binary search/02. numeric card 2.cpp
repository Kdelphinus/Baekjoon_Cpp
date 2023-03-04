/**
 * @file 02. numeric card 2.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 벡터의 기능 응용
 * @date 2021-08-23 23:06:48
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

    int n, m, tmp;
    cin >> n;
    vector<int> standard(n, 0);
    for (int i = 0; i < n; i++)
        cin >> standard[i];

    sort(standard.begin(), standard.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        // tmp와 같거나 큰 수 중 가장 첫번째 인덱스
        int start = lower_bound(standard.begin(), standard.end(), tmp) - standard.begin();

        // tmp보다 큰 수 중 가장 첫번째 인덱스
        int end = upper_bound(standard.begin(), standard.end(), tmp) - standard.begin();
        cout << end - start << " ";
    }
    return 0;
}