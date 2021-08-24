/**
 * @file 03. cut lan line.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-24 22:04:54
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int len = 1;
vector<long long> lines;

void cut(long long start, long long end, int n)
{
    if (start > end)
        return;

    long long cnt = 0;
    long long mid = (start + end) / 2;

    for (int i = 0; i < lines.size(); i++) // 현재 랜선으로 만들 수 있는 mid 길이의 랜선 수
        cnt += lines[i] / mid;

    if (cnt >= n) // 만들 수 있는 랜선의 수가 기준치를 충족할 때
    {
        if (mid > len)               // 원래보다 더 긴 랜선으로 만들 수 있다면
            len = mid;               // 만들 수 있는 랜선의 길이를 최신화하고
        return cut(mid + 1, end, n); // 더 긴 랜선 길이를 만들 수 있는지 확인
    }
    else                               // 기준을 충족하지 못하면
        return cut(start, mid - 1, n); // 더 짧은 랜선 길이를 확인
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int k, n;
    long long tmp;
    cin >> k >> n; // 가지고 있는 랜선의 개수, 필요한 랜선의 개수
    for (int i = 0; i < k; i++)
    {
        cin >> tmp;
        lines.push_back(tmp);
    }

    sort(lines.begin(), lines.end());

    cut(2, lines[k - 1], n);
    cout << len;

    return 0;
}