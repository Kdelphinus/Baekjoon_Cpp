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
        dp[i][i] = 1; // 한글자는 1자리 팰린드롬이다
        if (i > 0 && arr[i - 1] == arr[i])
            dp[i - 1][i] = 2; // 두 글자가 같으면 2자리 팰린드롬이다
    }

    for (int gap = 2; gap < num; gap++) // 2자리 글자까진 구했기에 gap은 2부터
    {
        for (int start = 0; start < num - gap; start++)
        {
            int end = start + gap;
            if (arr[start] == arr[end] && dp[start + 1][end - 1] != 0) // 맨 앞과 맨 뒤가 같고 그 사이가 팰린드롬이면 팰린드롬이다
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
        if (dp[start - 1][end - 1]) // 주어지는 인덱스는 1부터 시작
            cout << 1 << '\n';
        else // 0이면 팰린드롬이 아니다
            cout << 0 << '\n';
    }
    return 0;
}