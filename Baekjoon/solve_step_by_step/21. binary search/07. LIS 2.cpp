/**
 * @file 07. LIS 2.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-08 01:31:38
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> tmp;

int binary_search(int num)
{ // 오름차순되있는 arr에서 num이 들어갈 자리를 이분탐색으로 찾는 함수
    int start = 0, end = tmp.size() - 1;
    int index = 1000000;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (num <= tmp[mid]) // 중간값이 num보다 크거나 같을 때
        {
            if (index > mid)
                index = mid;
            end = mid - 1;
        }
        else // 중간값이 num보다 작을 때
            start = mid + 1;
    }
    return index;
}

int LIS(int num)
{
    for (int i = 0; i < num; i++)
    {
        // tmp가 비어있거나 arr[i]를 뒤에 넣어도 LIS를 만족할 때
        if (tmp.size() == 0 || tmp[tmp.size() - 1] < arr[i])
            tmp.push_back(arr[i]);
        // 뒤에 넣으면 LIS가 깨질 때, arr[i]가 들어갈 수 있는 위치에 있는 값을 arr[i]로 바꾼다
        // 기존의 값보다 무조건 작은 숫자가 들어가게 된다
        else
            tmp[binary_search(arr[i])] = arr[i];
    }

    // tmp 확인 코드, tmp는 길이는 답이지만 원소들은 답이 아니다
    //for (int i = 0; i < tmp.size(); i++)
    //    cout << tmp[i] << " ";
    //cout << '\n';
    return tmp.size();
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int num, tmp_num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp_num;
        arr.push_back(tmp_num);
    }
    cout << LIS(num);

    return 0;
}