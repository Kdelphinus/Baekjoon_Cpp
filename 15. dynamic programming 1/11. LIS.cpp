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
    vector<int> dp(num, 1); // �� ��ġ ���ڰ� ���������� �� ��, ���� �� �ִ� ���� �� LIS�� ���̸� ������ ����

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    for (int i = 1; i < num; i++)
    {
        for (int j = 0; j < i; j++) // ���� ��ġ���� ���� �͵��� Ȯ���Ѵ�
        {
            if (arr[i] > arr[j])               // ���� ���� ��ġ���� ���� �����
                dp[i] = max(dp[j] + 1, dp[i]); // ���ݱ��� ���� LIS�� arr[j]�� �̿��Ͽ� ���� LIS �� �� �� ���� �����´�
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