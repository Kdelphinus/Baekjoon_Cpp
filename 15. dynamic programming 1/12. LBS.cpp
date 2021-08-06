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
    vector<int> increase(num, 1); // LIS를 구하는 배열
    vector<int> decrease(num, 1); // LDS(계속 감소하는 배열의 최대 길이)나 LBS를 구하는 배열

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    for (int i = 1; i < num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j]) // LIS를 구하는 것과 동일
                increase[i] = max(increase[i], increase[j] + 1);
            if (arr[i] < arr[j]) // LDS를 이용하는 것과 LIS를 이용하여 LBS로 바꾸는 것 중 더 긴 것을 가져온다
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