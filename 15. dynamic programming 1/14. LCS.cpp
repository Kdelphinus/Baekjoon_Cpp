/**
 * @file 14. LCS.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 14. LCS.png 참고
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
            if (str1[i] == str2[j]) // 같은 문자가 나오면 그 전 최대 문자 길이에 1을 더한다
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else // 다른 문자가 나오면 그 위치에 다른 문자를 넣었을 때 가질 수 있는 최대값을 넣는다
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }

    return dp[str1.length()][str2.length()]; // 마지막 값이 LCS가 된다
}

int main()
{
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << lcs(str1, str2);
    return 0;
}