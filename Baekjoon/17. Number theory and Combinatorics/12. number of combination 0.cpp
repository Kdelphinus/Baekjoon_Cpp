/**
 * @file 12. number of combination 0.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-16 20:29:19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

long long fact_zero(long long num, long long check) // factorial num �ڿ� �پ��ִ� 0�� ������ ���ϴ� �Լ�
{
    long long cnt = 0, tmp = check;
    while (num >= check)
    {
        cnt += num / check;
        check *= tmp;
    }
    return cnt;
}

long long com_zero(long long n, long long m) // ���� n, m �ڿ� �پ��ִ� 0�� ������ ���ϴ� �Լ�
{
    // 10�� ���� �� �ִ� 2�� 5�� �� ���� ���� ���� �ڿ� ���� 0�� ������
    long long fact_five = fact_zero(n, 5) - fact_zero(m, 5) - fact_zero(n - m, 5);
    long long fact_two = fact_zero(n, 2) - fact_zero(m, 2) - fact_zero(n - m, 2);

    return min(fact_two, fact_five);
}

int main()
{
    long long n, m;
    cin >> n >> m;
    cout << com_zero(n, m);
    return 0;
}