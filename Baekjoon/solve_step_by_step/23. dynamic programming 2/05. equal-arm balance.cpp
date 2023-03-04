/**
 * @file 05. equal-arm balance.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-11 16:52:24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

int weight_num;
vector<int> weight(31, 0);                         // 추를 저장할 벡터
vector<int> possible(15001, 0);                    // 주어진 추로 잴 수 있는 무게, 15000 = 30(최대 추의 개수) * 500(하나의 추에 최대 무게)
vector<vector<int>> dp(31, vector<int>(15001, 0)); // dp[추가 저장된 인덱스][구할 수 있는 구슬의 무게]: 1이면 가능, 0이면 불가능

void balance(int idx, int left, int right)
{
    int diff = abs(left - right); // 현재 양 팔의 무게 차이

    if (possible[diff] == 0) // 새롭게 얻은 diff라면 가능으로 변경
        possible[diff] = 1;

    if (idx == weight_num) // 추를 다 사용했다면 함수 종료
        return;

    if (dp[idx][diff] == 0) // 새로운 무게조합일 경우
    {
        balance(idx + 1, left + weight[idx], right); // 왼쪽에다 추를 올리는 경우
        balance(idx + 1, left, right + weight[idx]); // 오른쪽에다 추를 올리는 경우
        balance(idx + 1, left, right);               // 추를 올리지 않는 경우

        dp[idx][diff] = 1; // 현재 상황에서 diff 무게의 구슬은 측정 가능
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> weight_num;
    for (int i = 0; i < weight_num; i++)
        cin >> weight[i];

    balance(0, 0, 0);

    int marble_num, tmp;
    cin >> marble_num;
    for (int i = 0; i < marble_num; i++)
    {
        cin >> tmp;
        if (possible[tmp] == 1)
            cout << 'Y' << ' ';
        else
            cout << 'N' << ' ';
    }

    return 0;
}