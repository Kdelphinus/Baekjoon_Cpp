/**
 * @file 02. self number.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-17 21:27:13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int numbers[10001];

void self_number(int num)
{
    int tmp;
    tmp = num;      // ���� ���� �����ϰ�
    while (tmp > 0) // �� �ڸ����� ���� ���� ���Ѵ�
    {
        num += tmp % 10;
        tmp /= 10;
    }

    numbers[num]++; // �� ���ڸ� ���� �ѹ��� �ƴ϶�� ǥ���ϰ�

    if (num <= 10000)     // ������ ����� �ʴ� ���� ��������ٸ�
        self_number(num); // ���� �ѹ��� �ƴ� ���� �� ã�´�
}

int main()
{
    for (int i = 1; i <= 10000; i++) // ���� �ȿ� ���� Ȯ��
    {
        if (numbers[i] == 0) // ���� �ѹ��� �ƴϸ�
        {
            std::cout << i << std::endl; // �� ���� ����ϰ�
            self_number(i);              // �� ���� ����� �ִ� ��� ���� �ѹ��� �ƴ� ���� ã�´�
        }
    }

    return 0;
}