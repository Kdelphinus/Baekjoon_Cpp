/**
 * @file 11. LIS.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-06 10:35:46
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(int num)
{
    int tmp;
    vector<int> arr;
    vector<int> dp(num, 1); // 그 위치 숫자가 마지막으로 들어갈 때, 만들 수 있는 가장 긴 LIS의 길이를 저장한 벡터

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    for (int i = 1; i < num; i++)
    {
        for (int j = 0; j < i; j++) // 현재 위치보다 이전 것들을 확인한다
        {
            if (arr[i] > arr[j])               // 만약 현재 위치보다 작은 수라면
                dp[i] = max(dp[j] + 1, dp[i]); // 지금까지 구한 LIS와 arr[j]를 이용하여 구한 LIS 중 더 긴 것을 가져온다
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main()
{
    int num;
    cin >> num;
    cout << lis(num);
    return 0;
}