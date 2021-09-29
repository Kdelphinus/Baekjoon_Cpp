/**
 * @file 08. big number A + B.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 15:15:56
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>

char result[10002];

int main()
{
    int tmp, len_a, len_b, len_r, idx = 0, flag = 0;
    std::string a, b; // ���ڰ� ũ�⿡ ���ڿ��� �޴´�
    std::cin >> a >> b;

    len_a = a.length() - 1;
    len_b = b.length() - 1;

    while (0 <= len_a && 0 <= len_b) // �� �� �ϳ��� ���� ��� �ڸ����� ���ߴٸ� ����
    {
        tmp = (a[len_a] - '0') + (b[len_b] - '0'); // ���� �ڸ����� ���� ���Ѵ�

        if (flag) // ���� ���� �ڸ������� �ö�� ���� �ִٸ� ���Ѵ�
            tmp++;

        if (tmp >= 10) // �ڸ����� ���� 10�� �Ѿ�� ���� �ڸ����� 1�� �ø��� �������� ���Ѵ�
        {
            flag = 1;
            tmp %= 10;
        }
        else if (flag == 1) // �ڸ����� ���� 10�� ���� �ʴµ� flag�� 1�̶�� 0���� �ٲ��ش�
            flag = 0;

        result[idx] = tmp + '0'; // �ڸ����� ���� ���ڿ��� �����Ѵ�
        idx++;                   // result �ε��� �̵�
        len_a--;                 // ���� �ڸ����� �̵�
        len_b--;                 // ���� �ڸ����� �̵�
    }

    if (0 <= len_a) // ���� a�� ���� ���Ҵٸ�
    {
        while (flag) // �ڸ��� �ø����� ���� �ִٸ�
        {
            if (len_a >= 0)                   // ���� a�� ���Ҵٸ�
                tmp = (a[len_a--] - '0') + 1; // ���� �Ͱ� �ö�� ���� ���ϰ�
            else                              // a�� ��� ���ߴٸ�
                tmp = 1;                      // �ö�� �͸� ���� �ڸ��� ���Ѵ�
            if (tmp >= 10)                    // tmp�� 10�� �Ѵ´ٸ� ���� �ڸ��� ���� �ø���
                tmp %= 10;
            else // �ƴ϶�� flag�� 0���� �ٲ۴�
                flag = 0;
            result[idx++] = tmp + '0'; // ���� �ڸ����� ����
        }
        for (int i = len_a; i >= 0; i--) // ���� a�� ��� �����Ѵ�
            result[idx++] = a[i];
    }
    else if (0 <= len_b) // ���� b�� ���Ҵٸ� a�� ���� ������� ���� ���� ����
    {
        while (flag)
        {
            if (len_b >= 0)
                tmp = (b[len_b--] - '0') + 1;
            else
                tmp = 1;
            if (tmp >= 10)
                tmp %= 10;
            else
                flag = 0;
            result[idx++] = tmp + '0';
        }
        for (int i = len_b; i >= 0; i--)
            result[idx++] = b[len_b];
    }
    else if (flag) // ���� �� �� ��� �������� �ö�� ���� �ִٸ� ���� �ڸ��� 1�� �߰�
        result[idx++] = '1';

    for (int i = idx - 1; i > -1; i--) // �Ųٷ� ���
    {
        std::cout << result[i];
    }

    return 0;
}