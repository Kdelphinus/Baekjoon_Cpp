/**
 * @file 11. number of factorial 0.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-16 20:19:25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

// ���丮���� ���� ���ʴ�� ���ϴ� ���̴�.
// 10�� ����� ���� ������ 0�� �ϳ��� ���� ���̰� 10�� 2�� 5�� ������ ���� �� �ִ�
// 5�� ������� 2�� ����� �е������� ���⿡ 5�� ����� ������ ���ϸ� �ڿ� ���� 0�� ������ ���� �� �ִ�
int fact_zero(int num)
{
    int cnt = num / 5 + num / 25 + num / 125;
    return cnt;
}

int main()
{
    int num;
    cin >> num;
    cout << fact_zero(num);
    return 0;
}