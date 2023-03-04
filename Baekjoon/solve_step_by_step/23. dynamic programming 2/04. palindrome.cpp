/**
 * @file 04. palindrome.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-10 19:35:41
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

int num;
vector<int> arr;
vector<vector<int>> dp;

void palindrome()
{
    for (int i = 0; i < num; i++)
    {
        dp[i][i] = 1; // �ѱ��ڴ� 1�ڸ� �Ӹ�����̴�
        if (i > 0 && arr[i - 1] == arr[i])
            dp[i - 1][i] = 2; // �� ���ڰ� ������ 2�ڸ� �Ӹ�����̴�
    }

    for (int gap = 2; gap < num; gap++) // 2�ڸ� ���ڱ��� ���߱⿡ gap�� 2����
    {
        for (int start = 0; start < num - gap; start++)
        {
            int end = start + gap;
            if (arr[start] == arr[end] && dp[start + 1][end - 1] != 0) // �� �հ� �� �ڰ� ���� �� ���̰� �Ӹ�����̸� �Ӹ�����̴�
                dp[start][end] = dp[start + 1][end - 1] + 2;
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int tmp, order_num, start, end;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);

        vector<int> tmp_vec(num);
        dp.push_back(tmp_vec);
    }

    palindrome();

    cin >> order_num;
    for (int i = 0; i < order_num; i++)
    {
        cin >> start >> end;
        if (dp[start - 1][end - 1]) // �־����� �ε����� 1���� ����
            cout << 1 << '\n';
        else // 0�̸� �Ӹ������ �ƴϴ�
            cout << 0 << '\n';
    }
    return 0;
}