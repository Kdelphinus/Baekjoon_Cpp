/**
 * @file 01. find a number.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-23 22:50:17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> standard; // 벡터를 함수로 받으면 시간 초과가 자주 발생한다

int bs(int tmp)
{
    int start = 0;
    int end = standard.size() - 1;

    while (start < end) // 무조건 시작지점은 끝지점보다 작아야한다
    {
        int mid = (start + end) / 2;

        // 세 부분 중 하나라도 겹치는 곳이 있으면 값이 있는 것임으로 1리턴
        if (standard[start] == tmp)
            return 1;
        if (standard[mid] == tmp)
            return 1;
        if (standard[end] == tmp)
            return 1;

        if (standard[mid] < tmp) // 중간보다 크면 벡터의 오른쪽만 확인하면 된다
            start = mid + 1;
        else // 중간보다 작으면 벡터의 왼쪽만 확인하면 된다
            end = mid - 1;
    }

    return 0; // 시작지점이 끝지점보다 커지면 값이 없다
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

    sort(standard.begin(), standard.end()); // 기준이 되는 것은 정렬

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        cout << bs(tmp) << '\n';
    }

    return 0;
}