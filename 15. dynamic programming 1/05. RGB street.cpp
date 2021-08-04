/**
 * @file 05. RGB street.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-04 18:50:17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> price(1001, vector<int>(3, 0)); // r, g, b ������� ������ ����
vector<vector<int>> dp(1001, vector<int>(3, 0));    // Ư�� ���� ĥ���� �� �ּ� ����

int min_price(int num)
{
    // �ʱⰪ
    dp[0][0] = price[0][0];
    dp[0][1] = price[0][1];
    dp[0][2] = price[0][2];

    for (int i = 1; i < num; i++)
    {
        dp[i][0] += price[i][0] + min(dp[i - 1][1], dp[i - 1][2]); // r�� ĥ�ϸ� �� ���� r�� ĥ���� ���� �� �� �ּ� ������ �����´�
        dp[i][1] += price[i][1] + min(dp[i - 1][0], dp[i - 1][2]); // g�� ĥ�ϸ� �� ���� g�� ĥ���� ���� �� �� �ּ� ������ �����´�
        dp[i][2] += price[i][2] + min(dp[i - 1][1], dp[i - 1][0]); // b�� ĥ�ϸ� �� ���� b�� ĥ���� ���� �� �� �ּ� ������ �����´�
    }

    return min(dp[num - 1][0], min(dp[num - 1][1], dp[num - 1][2]));
}

int main()
{
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int r, g, b;
        cin >> r >> g >> b;
        price[i][0] = r;
        price[i][1] = g;
        price[i][2] = b;
    }

    cout << min_price(num);

    return 0;
}