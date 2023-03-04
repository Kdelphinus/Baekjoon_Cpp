#include <iostream>
#include <vector>
using namespace std;

vector<int> coins;     // ������ �ִ� �������� ������ ����
vector<int> dp(10001); // dp[idx]: idx�� ���� �� �ִ� ����� ��

int number_of_cases(int num, int goal)
{
    dp[0] = 1; // ���� �ϳ��� ���� ����� ���� ���� �⺻��
    for (int i = 0; i < num; i++)
    {
        for (int j = 1; j <= goal; j++)
        {
            if (coins[i] <= j)             // ���� ������ ��ǥ�� ���Ͽ��� ���� �� �ִ�
                dp[j] += dp[j - coins[i]]; // ���� ������ �� ���� ����� ����ŭ ����� �� ����
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