/**
 * @file 10. wine tasting.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-06 10:22:51
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

int wine_tasting(int num)
{
    int tmp;
    vector<int> wine;
    vector<int> dp(num, 0);

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        wine.push_back(tmp);
    }

    if (num == 1)
        return wine[0];

    if (num == 2)
        return wine[1] + wine[0];

    dp[0] = wine[0];
    dp[1] = wine[1] + wine[0];
    dp[2] = max(dp[1], max(wine[2] + wine[0], wine[2] + wine[1]));

    // 현재 잔을 마시지 않는 방법, 현재 잔과 전전 잔을 마시는 방법, 현재 잔과 전 잔을 마시는 방법 중 하나를 택한다
    for (int i = 3; i < num; i++)
        dp[i] = max(dp[i - 1], max(dp[i - 2] + wine[i], wine[i] + wine[i - 1] + dp[i - 3]));

    return dp[num - 1];
}

int main()
{
    int num;
    cin >> num;
    cout << wine_tasting(num);
    return 0;
}