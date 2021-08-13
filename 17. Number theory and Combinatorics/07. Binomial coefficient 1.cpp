/**
 * @file 07. Binomial coefficient 1.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-13 22:51:37
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> factorial(1, 1); // 초기값 0! = 1

int fact(int n) // 팩토리얼을 구하는 함수
{
    if (factorial.size() > n) // 이미 구한 것이면 바로 리턴
        return factorial[n];

    for (int i = factorial.size(); i <= n; i++) // 구하지 않은 값이면 구한 마지막 값부터 계산
        factorial.push_back(factorial[i - 1] * i);

    return factorial[n];
}

int bc(int a, int b) // 이항 계수를 구하는 함수
{
    return fact(a) / (fact(b) * fact(a - b));
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << bc(a, b);
    return 0;
}