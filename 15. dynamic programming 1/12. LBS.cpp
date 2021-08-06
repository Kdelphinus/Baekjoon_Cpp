/**
 * @file 12. LBS.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-06 10:53:32
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lbs(int num)
{
    int tmp;
    vector<int> arr;
    vector<int> increase(num, 1); // LIS�� ���ϴ� �迭
    vector<int> decrease(num, 1); // LDS(��� �����ϴ� �迭�� �ִ� ����)�� LBS�� ���ϴ� �迭

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    for (int i = 1; i < num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j]) // LIS�� ���ϴ� �Ͱ� ����
                increase[i] = max(increase[i], increase[j] + 1);
            if (arr[i] < arr[j]) // LDS�� �̿��ϴ� �Ͱ� LIS�� �̿��Ͽ� LBS�� �ٲٴ� �� �� �� �� ���� �����´�
                decrease[i] = max(increase[j] + 1, max(decrease[i], decrease[j] + 1));
        }
    }

    return max(*max_element(increase.begin(), increase.end()), *max_element(decrease.begin(), decrease.end()));
}

int main()
{
    int num;
    cin >> num;
    cout << lbs(num);
    return 0;
}