/**
 * @file 05. Bertrand's postulate.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 19:37:39
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cmath>

int numbers[123457 * 2];

void prime_list()
{
    numbers[0] = 1;
    numbers[1] = 1;

    for (int i = 2; i <= sqrt(123456 * 2); i++)
    {
        if (numbers[i] == 0)
        {
            for (int j = i + i; j <= 123456 * 2; j += i)
                numbers[j] = 1;
        }
    }
}

int main()
{
    prime_list();
    while (1)
    {
        int n, cnt = 0;
        std::cin >> n;

        if (n == 0)
            break;

        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (numbers[i] == 0)
                cnt++;
        }

        printf("%d\n", cnt);
    }
    return 0;
}