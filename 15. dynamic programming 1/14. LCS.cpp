/**
 * @file 14. LCS.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 14. LCS.png ����
 * @date 2021-08-09 12:55:12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcs(string str1, string str2)
{
    vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));

    for (int i = 0; i < str1.length(); i++)
    {
        for (int j = 0; j < str2.length(); j++)
        {
            if (str1[i] == str2[j]) // ���� ���ڰ� ������ �� �� �ִ� ���� ���̿� 1�� ���Ѵ�
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else // �ٸ� ���ڰ� ������ �� ��ġ�� �ٸ� ���ڸ� �־��� �� ���� �� �ִ� �ִ밪�� �ִ´�
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }

    return dp[str1.length()][str2.length()]; // ������ ���� LCS�� �ȴ�
}

int main()
{
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << lcs(str1, str2);
    return 0;
}