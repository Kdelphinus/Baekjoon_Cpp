/**
 * @file 02. matrix multiplication order.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-10 18:18:42
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int MMO(int num)
{
    vector<vector<int>> dp(num, vector<int>(num, 0));
    vector<vector<int>> matrix(num, vector<int>(2, 0));
    for (int i = 0; i < num; i++)
        cin >> matrix[i][0] >> matrix[i][1];

    for (int gap = 1; gap < num; gap++)
    {
        for (int start = 0; start < num - gap; start++)
        {
            int end = start + gap;
            dp[start][end] = numeric_limits<int>::max();
            for (int i = start; i < end; i++)
                dp[start][end] = min(dp[start][end], dp[start][i] + dp[i + 1][end] + matrix[start][0] * matrix[i][1] * matrix[end][1]);
        }
    }

    return dp[0][num - 1];
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int num;
    cin >> num;
    cout << MMO(num);

    return 0;
}