/**
 * @file 01. combining files.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 누적비용을 유의할 것
 * @date 2021-10-09 20:09:52
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<int> part(501);

int combine(int part_num)
{
    vector<vector<int>> dp(part_num, vector<int>(part_num, 0)); // dp[start][end]: start ~ end까지 합쳤을 때 나오는 최소 비용
    vector<int> sum(part_num + 1, 0);                           // 누적합을 저장할 벡터

    sum[0] = part[0];
    for (int i = 1; i < part_num; i++)
        sum[i] = part[i] + sum[i - 1];

    for (int gap = 1; gap < part_num; gap++) // gap = end - start
    {
        for (int start = 0; start < part_num - gap; start++)
        {
            int end = start + gap;
            dp[start][end] = numeric_limits<int>::max(); // 최댓값으로 초기화

            // dp[start][i] + dp[i + 1][end]: start ~ i와 i + 1 ~ end의 문서를 합치는데 드는 비용
            // sum[end] - sum[start - 1]: start ~ end까지 더하는데 드는 누적 비용
            // c2 ~ c4를 합칠 때: min(c2 + c3 비용, c3 + c4 비용) + c2 + c3 + c4
            for (int i = start; i < end; i++)
            {
                if (start == 0) // start가 0이면 부분합은 그대로 가져와도 된다
                    dp[start][end] = min(dp[start][end], dp[start][i] + dp[i + 1][end] + sum[end]);
                else // start가 0이 아니면 부분합은 sum[end] - sum[start - 1]로 가져와야 한다
                    dp[start][end] = min(dp[start][end], dp[start][i] + dp[i + 1][end] + sum[end] - sum[start - 1]);
            }
        }
    }

    return dp[0][part_num - 1];
}

int main()
{
    int test, tmp;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        int part_num;
        cin >> part_num;

        for (int j = 0; j < part_num; j++)
            cin >> part[j];

        cout << combine(part_num) << '\n';
    }
    return 0;
}