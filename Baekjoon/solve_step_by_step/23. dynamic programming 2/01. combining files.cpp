/**
 * @file 01. combining files.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief ��������� ������ ��
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
    vector<vector<int>> dp(part_num, vector<int>(part_num, 0)); // dp[start][end]: start ~ end���� ������ �� ������ �ּ� ���
    vector<int> sum(part_num + 1, 0);                           // �������� ������ ����

    sum[0] = part[0];
    for (int i = 1; i < part_num; i++)
        sum[i] = part[i] + sum[i - 1];

    for (int gap = 1; gap < part_num; gap++) // gap = end - start
    {
        for (int start = 0; start < part_num - gap; start++)
        {
            int end = start + gap;
            dp[start][end] = numeric_limits<int>::max(); // �ִ����� �ʱ�ȭ

            // dp[start][i] + dp[i + 1][end]: start ~ i�� i + 1 ~ end�� ������ ��ġ�µ� ��� ���
            // sum[end] - sum[start - 1]: start ~ end���� ���ϴµ� ��� ���� ���
            // c2 ~ c4�� ��ĥ ��: min(c2 + c3 ���, c3 + c4 ���) + c2 + c3 + c4
            for (int i = start; i < end; i++)
            {
                if (start == 0) // start�� 0�̸� �κ����� �״�� �����͵� �ȴ�
                    dp[start][end] = min(dp[start][end], dp[start][i] + dp[i + 1][end] + sum[end]);
                else // start�� 0�� �ƴϸ� �κ����� sum[end] - sum[start - 1]�� �����;� �Ѵ�
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