/**
 * @file 10. Fashion king.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-16 20:12:45
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long fashion(int num)
{
    string str1, str2;
    vector<string> strs;
    long long anw = 1, tmp = 1;

    if (num == 0) // 옷의 종류가 없다면 경우의 수도 0이다
        return 0;

    for (int i = 0; i < num; i++)
    {
        cin >> str1 >> str2;
        strs.push_back(str2); // 종류만 저장함
    }

    sort(strs.begin(), strs.end()); // 정렬
    str1 = strs[0];                 // 첫번째 값 저장
    for (int i = 1; i < num; i++)
    {
        if (str1 == strs[i]) // 같은 종류면 종류 수를 추가
            tmp++;
        else // 다른 종류면 이전 종류의 경우의 수를 구하고 다음 종류의 수를 구함
        {
            anw *= (tmp + 1); // 벗는 경우도 포함하여 계산
            tmp = 1;
            str1 = strs[i];
        }
    }

    anw *= (tmp + 1); // 마지막 종류도 계산

    return anw - 1; // 다 벗는 경우는 제거
}

int main()
{
    int test;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        int num;
        cin >> num;
        cout << fashion(num) << '\n';
    }
    return 0;
}