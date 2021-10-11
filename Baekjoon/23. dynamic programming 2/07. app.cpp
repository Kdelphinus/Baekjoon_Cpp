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
    vector<vector<int>> dp(num + 1, vector<int>(total_price + 1, 0)); // dp[num][cost]: num���� �� �� cost��ŭ ����Ͽ� ���� �� �ִ� memory�� �ִ�

    for (int i = 1; i <= num; i++)
    {
        int memory = app_memory[i]; // ���� ���� �޸�
        int price = app_price[i];   // ���� ���� �������� �� ���

        for (int j = 1; j <= total_price; j++)
        {
            if (j < price)                                                   // ���� ���� ��Ȱ��ȭ �� �� ���� ��
                dp[i][j] = dp[i - 1][j];                                     // ���� ���� ���� �ʴ´�
            else                                                             // ���� ���� ��Ȱ��ȭ �� �� ���� ��
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price] + memory); // ���� ���� ���� �ʴ� �Ͱ� ���� �� �� �޸𸮸� �� ���� �� �ִ� ������ ����

            if (dp[i][j] >= need_memory) // Ȯ���� �޸𸮰� �ʿ��� �޸� �̻��̶��
                result = min(result, j); // ���� ����� �ּڰ����� �ֽ�ȭ�Ѵ�
        }
    }

    return result;
}

int main()
{
    int tmp, num, need_memory;
    cin >> num >> need_memory;

    // �ʿ� �޸𸮰� 0�� �� ���� �߰�, ���� �޸𸮸� Ȯ���ϱ� ������ �ʿ�
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