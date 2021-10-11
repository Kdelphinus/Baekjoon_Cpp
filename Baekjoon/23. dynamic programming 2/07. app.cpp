/**
 * @file 07. app.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-11 18:24:02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> app_memory;
vector<int> app_price;

int min_price(int num, int need_memory)
{
    int result = accumulate(app_price.begin(), app_price.end(), 0);
    int total_price = accumulate(app_price.begin(), app_price.end(), 0);
    vector<vector<int>> dp(num + 1, vector<int>(total_price + 1, 0)); // dp[num][cost]: num개의 앱 중 cost만큼 사용하여 얻을 수 있는 memory의 최댓값

    for (int i = 1; i <= num; i++)
    {
        int memory = app_memory[i]; // 현재 앱의 메모리
        int price = app_price[i];   // 현재 앱을 종료했을 때 비용

        for (int j = 1; j <= total_price; j++)
        {
            if (j < price)                                                   // 현재 앱을 비활성화 할 수 없을 때
                dp[i][j] = dp[i - 1][j];                                     // 현재 앱을 끄지 않는다
            else                                                             // 현재 앱을 비활성화 할 수 있을 때
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price] + memory); // 현재 앱을 끄지 않는 것과 끄는 것 중 메모리를 더 얻을 수 있는 것으로 저장

            if (dp[i][j] >= need_memory) // 확보한 메모리가 필요한 메모리 이상이라면
                result = min(result, j); // 사용된 비용을 최솟값으로 최신화한다
        }
    }

    return result;
}

int main()
{
    int tmp, num, need_memory;
    cin >> num >> need_memory;

    // 필요 메모리가 0일 때 값을 추가, 이전 메모리를 확인하기 때문에 필요
    app_memory.push_back(0);
    app_price.push_back(0);
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        app_memory.push_back(tmp);
    }

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        app_price.push_back(tmp);
    }

    cout << min_price(num, need_memory);

    return 0;
}