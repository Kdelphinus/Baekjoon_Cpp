/**
 * @file 03. taking a star - 10.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 20:52:28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

char star[6562][6562];

void taking_star(int n, int div_n)
{
    if (n == div_n)
    {
        star[1][1] = ' '; // n�� 3�� ���� ���� ���
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % 3 == 1 && j % 3 == 1) // ���
                star[i][j] = ' ';
            if (i >= n / 3 && i < n * 2 / 3 && j >= n / 3 && j < n * 2 / 3) // ��ü �׸� �� ���
                star[i][j] = ' ';
            else
            {
                if (i >= div_n / 3 && i < div_n * 2 / 3 && j >= div_n / 3 && j < div_n * 2 / 3) // �� ���� �߿��� ���
                    star[i][j] = ' ';
                else
                    star[i][j] = star[i % div_n][j % div_n]; // ������ �κ��� ���� ��ܰ� �����ϰ� ����
            }
        }
    }

    taking_star(n, div_n * 3);
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            star[i][j] = '*';
    }

    taking_star(n, 3);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c", star[i][j]);
        printf("\n");
    }

    return 0;
}