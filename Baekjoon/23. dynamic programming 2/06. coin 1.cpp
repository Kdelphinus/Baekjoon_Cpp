#include <iostream>
#include <vector>
using namespace std;

vector<int> coins;     // 가지고 있는 동전들을 저장할 벡터
vector<int> dp(10001); // dp[idx]: idx를 만들 수 있는 경우의 수

int number_of_cases(int num, int goal)
{
    dp[0] = 1; // 동전 하나로 만들 경우의 수를 위한 기본값
    for (int i = 0; i < num; i++)
    {
        for (int j = 1; j <= goal; j++)
        {
            if (coins[i] <= j)             // 현재 동전이 목표값 이하여야 만들 수 있다
                dp[j] += dp[j - coins[i]]; // 현재 동전을 뺀 값의 경우의 수만큼 경우의 수 존재
        }
    }

    return dp[goal];
}

int main()
{
    int num, goal, tmp;
    cin >> num >> goal;

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        coins.push_back(tmp);
    }

    cout << number_of_cases(num, goal);

    return 0;
}