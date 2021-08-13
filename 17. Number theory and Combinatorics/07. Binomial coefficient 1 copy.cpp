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

vector<int> factorial(1, 1); // �ʱⰪ 0! = 1

int fact(int n) // ���丮���� ���ϴ� �Լ�
{
    if (factorial.size() > n) // �̹� ���� ���̸� �ٷ� ����
        return factorial[n];

    for (int i = factorial.size(); i <= n; i++) // ������ ���� ���̸� ���� ������ ������ ���
        factorial.push_back(factorial[i - 1] * i);

    return factorial[n];
}

int bc(int a, int b) // ���� ����� ���ϴ� �Լ�
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