/**
 * @file 02. numeric card 2.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-23 23:06:48
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;
vector<int> standard;

void bs(int tmp, int start, int end)
{
    if (start > end) // 시작지점이 끝지점보다 크면 찾는 값 없음
        return;

    int mid = (start + end) / 2;

    if (standard[mid] > tmp) // 중간값보다 작다면 벡터의 왼쪽만 확인
        bs(tmp, start, mid - 1);
    else if (standard[mid] < tmp) // 중간값보다 크다면 벡터의 오른쪽만 확인
        bs(tmp, mid + 1, end);
    else // 중간값과 같다면 개수를 추가하고 오른쪽과 왼쪽 모두 확인
    {
        cnt++;
        bs(tmp, start, mid - 1), bs(tmp, mid + 1, end);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        standard.push_back(tmp);
    }

    sort(standard.begin(), standard.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        bs(tmp, 0, n - 1);
        cout << cnt << " ";
        cnt = 0;
    }
    return 0;
}