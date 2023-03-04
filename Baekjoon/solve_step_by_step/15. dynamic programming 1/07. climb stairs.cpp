/**
 * @file 07. climb stairs.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-05 21:22:26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> stairs;

int dynamic_programming(int num)
{
    if (num == 1) // 계단이 하나일 때
        return stairs[0];

    if (num == 2) // 계단이 두 개 일때
        return stairs[0] + stairs[1];

    // 초기값 설정
    int dp[num] = {0}; // 그 위치를 밟았을 때, 최고 점수를 저장하는 배열
    dp[0] = stairs[0];
    dp[1] = dp[0] + stairs[1];
    dp[2] = stairs[2] + max(stairs[0], stairs[1]);

    // 직전 계단을 밟는 것과 전전 계단을 밟는 것 중 더 큰 점수를 얻는 것으로 선택
    for (int i = 3; i < num; i++)
        dp[i] = stairs[i] + max(stairs[i - 1] + dp[i - 3], dp[i - 2]);

    return dp[num - 1]; // 마지막 계단은 무조건 밟아야 한다
}

int main()
{
    int num, tmp;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        stairs.push_back(tmp);
    }

    cout << dynamic_programming(num);

    return 0;
}