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
vector<int> weight(31, 0);                         // �߸� ������ ����
vector<int> possible(15001, 0);                    // �־��� �߷� �� �� �ִ� ����, 15000 = 30(�ִ� ���� ����) * 500(�ϳ��� �߿� �ִ� ����)
vector<vector<int>> dp(31, vector<int>(15001, 0)); // dp[�߰� ����� �ε���][���� �� �ִ� ������ ����]: 1�̸� ����, 0�̸� �Ұ���

void balance(int idx, int left, int right)
{
    int diff = abs(left - right); // ���� �� ���� ���� ����

    if (possible[diff] == 0) // ���Ӱ� ���� diff��� �������� ����
        possible[diff] = 1;

    if (idx == weight_num) // �߸� �� ����ߴٸ� �Լ� ����
        return;

    if (dp[idx][diff] == 0) // ���ο� ���������� ���
    {
        balance(idx + 1, left + weight[idx], right); // ���ʿ��� �߸� �ø��� ���
        balance(idx + 1, left, right + weight[idx]); // �����ʿ��� �߸� �ø��� ���
        balance(idx + 1, left, right);               // �߸� �ø��� �ʴ� ���

        dp[idx][diff] = 1; // ���� ��Ȳ���� diff ������ ������ ���� ����
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