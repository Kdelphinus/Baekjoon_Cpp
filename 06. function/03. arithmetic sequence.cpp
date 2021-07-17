/**
 * @file 03. arithmetic sequence.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-17 21:51:06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

bool check(int num) // �Ѽ����� üũ�ϴ� �Լ�
{
    int tmp, diff, flag = 0;

    while (num > 0)
    {
        if (flag == 0) // ���� �ڸ���
        {
            tmp = num % 10; // �ӽ� ������ ����
            num /= 10;
            flag++;
        }
        else if (flag == 1) // ���� �ڸ���
        {
            diff = tmp - num % 10; // �� �ڸ��� ���̸� ����
            tmp = num % 10;
            num /= 10;
            flag++;
        }
        else // ���� �ڸ����� ~
        {
            if (diff != tmp - num % 10) // ���� ���̿� ���� ���̰� ���� �ʴٸ�
            {
                flag = 0; // �Ѽ� �ƴ�
                break;
            }
            tmp = num % 10;
            num /= 10;
        }
    }

    if (flag)
        return true;

    return false;
}

int arithmetic_sequence(int num)
{
    if (num <= 99) // 99 ���ϴ� ��� �Ѽ��̴�
        return num;

    int cnt = 99;
    for (int i = 100; i <= num; i++) // 99������ ��� �Ѽ��̹Ƿ� 100���� Ȯ��
    {
        if (check(i)) // �Ѽ��̸� ī��Ʈ �߰�
            cnt++;
    }

    return cnt;
}

int main()
{
    int num;
    std::cin >> num;
    std::cout << arithmetic_sequence(num);

    return 0;
}