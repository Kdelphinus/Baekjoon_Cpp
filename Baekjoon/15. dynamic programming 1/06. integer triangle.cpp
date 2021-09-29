/**
 * @file 06. integer triangle.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-04 23:25:28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

int triangle[501][501];

int max_sum(int num)
{
    int dp[num][num] = {0};       // 각 위치에서 가질 수 있는 최댓값, 밑에서부터 올라오며 계산
    for (int i = 0; i < num; i++) // 가장 밑의 층은 그 수가 최댓값이다
        dp[num - 1][i] = triangle[num - 1][i];

    for (int i = num - 2; i >= 0; i--) // 밑에 있는 두 수 중, 더 큰 값을 더한다
    {
        for (int j = 0; j <= i; j++)
            dp[i][j] = triangle[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
    }

    return dp[0][0];
}

int main()
{
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
            cin >> triangle[i][j];
    }

    cout << max_sum(num);

    return 0;
}