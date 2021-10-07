/**
 * @file 06. K number.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-07 23:01:37
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

long long k_num(int n, long long target, long long start, long long end)
{
    if (start > end)
        return start;

    long long cnt = 0, mid = (start + end) / 2;
    for (int i = 1; i <= n; i++)
    {
        if (mid / i > n) // n�࿡ ����ִ� ��� ���� mid���� ���� ��
            cnt += n;
        else // n�࿡ ����ִ� �� �� mid���� ū ���� ���� ��
            cnt += mid / i;
    }

    // mid�� ��ü ���ڿ��� cnt��° ���̴�
    if (cnt < target) // ���� ���� cnt���� ũ�� mid���� ū ���̴�
        return k_num(n, target, mid + 1, end);
    else // ���� ���� cnt���� �۰ų� ������ mid���� �۰ų� ���� ���̴�
        return k_num(n, target, start, mid - 1);
}

int main()
{
    int n;
    long long target;
    cin >> n;
    cin >> target;
    cout << k_num(n, target, 1, target);
    return 0;
}