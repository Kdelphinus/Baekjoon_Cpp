/**
 * @file 15. continuous sum.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-09 13:08:59
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int continuous_sum(int num, vector<int> numbers)
{
    vector<int> dp(num, 0);
    dp[0] = numbers[0]; // 첫 값은 자기 자신이 가장 큰 연속합이다

    for (int i = 1; i < num; i++) // 전 값과 더한값과 자신 중 더 큰 값을 저장한다
        dp[i] = max(dp[i - 1] + numbers[i], numbers[i]);

    return *max_element(dp.begin(), dp.end()); // 구한 연속합들 중 가장 큰 값을 리턴한다
}

int main()
{
    int num;
    cin >> num;
    vector<int> numbers(num, 0);
    for (int i = 0; i < num; i++)
        cin >> numbers[i];
    cout << continuous_sum(num, numbers);
    return 0;
}