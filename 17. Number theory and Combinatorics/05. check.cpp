/**
 * @file 05. check.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-13 22:27:48
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b) // 최대공약수를 구하는 함수
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void check(int num)
{
    vector<int> arr(num, 0);
    for (int i = 0; i < num; i++)
        cin >> arr[i];

    int tmp = abs(arr[1] - arr[0]);
    for (int i = 2; i < num; i++) // 각 원소의 차이들의 최대공약수를 구한다
        tmp = gcd(abs(arr[i] - arr[i - 1]), tmp);

    vector<int> anw;
    anw.push_back(tmp);
    for (int i = 2; i <= sqrt(tmp); i++) // 구한 최대공약수의 약수들이 답
    {
        if (tmp % i == 0)
        {
            anw.push_back(i);
            anw.push_back(tmp / i);
        }
    }

    sort(anw.begin(), anw.end());                         // 정렬 후
    anw.erase(unique(anw.begin(), anw.end()), anw.end()); // 중복된 값 제거
    for (int i = 0; i < anw.size(); i++)
        cout << anw[i] << " ";
}

int main()
{
    int num;
    cin >> num;
    check(num);
    return 0;
}