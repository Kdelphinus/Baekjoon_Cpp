/**
 * @file 01. black jack.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 21:08:38
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int n, limit, value = 0;
    scanf("%d %d", &n, &limit);

    int card[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &card[i]);

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int tmp = card[i] + card[j] + card[k];
                if (value < tmp && tmp <= limit)
                    value = tmp;
            }
        }
    }

    printf("%d", value);

    return 0;
}