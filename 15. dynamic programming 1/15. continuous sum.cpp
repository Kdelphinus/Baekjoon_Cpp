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
    dp[0] = numbers[0]; // ù ���� �ڱ� �ڽ��� ���� ū �������̴�

    for (int i = 1; i < num; i++) // �� ���� ���Ѱ��� �ڽ� �� �� ū ���� �����Ѵ�
        dp[i] = max(dp[i - 1] + numbers[i], numbers[i]);

    return *max_element(dp.begin(), dp.end()); // ���� �����յ� �� ���� ū ���� �����Ѵ�
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