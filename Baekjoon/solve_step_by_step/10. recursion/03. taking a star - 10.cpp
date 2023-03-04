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
        star[1][1] = ' '; // n이 3이 들어올 때를 대비
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % 3 == 1 && j % 3 == 1) // 가운데
                star[i][j] = ' ';
            if (i >= n / 3 && i < n * 2 / 3 && j >= n / 3 && j < n * 2 / 3) // 전체 그림 중 가운데
                star[i][j] = ' ';
            else
            {
                if (i >= div_n / 3 && i < div_n * 2 / 3 && j >= div_n / 3 && j < div_n * 2 / 3) // 각 패턴 중에서 가운데
                    star[i][j] = ' ';
                else
                    star[i][j] = star[i % div_n][j % div_n]; // 나머지 부분은 왼쪽 상단과 동일하게 복사
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