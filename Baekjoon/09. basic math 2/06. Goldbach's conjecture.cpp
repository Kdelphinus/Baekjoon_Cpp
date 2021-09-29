/**
 * @file 06. Goldbach's conjecture.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 19:47:58
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cmath>

int prime_list[10001];

void prime_number()
{
    prime_list[0] = 1;
    prime_list[1] = 1;

    for (int i = 2; i <= sqrt(10000); i++)
    {
        if (prime_list[i] == 0)
        {
            for (int j = i + i; j <= 10000; j += i)
                prime_list[j] = 1;
        }
    }
}

int main()
{
    int test;
    prime_number();

    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int num;
        scanf("%d", &num);

        for (int j = num / 2; j > 1; j--)
        {
            if (prime_list[j] == 0 && prime_list[num - j] == 0)
            {
                printf("%d %d\n", j, num - j);
                break;
            }
        }
    }

    return 0;
}