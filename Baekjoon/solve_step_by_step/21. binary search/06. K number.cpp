/**
 * @file 06. K number.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-07 23:01:37
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

long long k_num(int n, long long target, long long start, long long end)
{
    if (start > end)
        return start;

    long long cnt = 0, mid = (start + end) / 2;
    for (int i = 1; i <= n; i++)
    {
        if (mid / i > n) // n행에 들어있는 모든 수가 mid보다 작을 때
            cnt += n;
        else // n행에 들어있는 수 중 mid보다 큰 수가 있을 때
            cnt += mid / i;
    }

    // mid는 전체 숫자에서 cnt번째 수이다
    if (cnt < target) // 구할 수가 cnt보다 크면 mid보다 큰 수이다
        return k_num(n, target, mid + 1, end);
    else // 구할 수가 cnt보다 작거나 같으면 mid보다 작거나 같은 수이다
        return k_num(n, target, start, mid - 1);
}

int main()
{
    int n;
    long long target;
    cin >> n;
    cin >> target;
    cout << k_num(n, target, 1, target);
    return 0;
}