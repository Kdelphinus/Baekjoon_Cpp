/**
 * @file 02. decomposition.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-25 17:15:35
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int decomp(int n)
{
    for (int i = 1; i < n; i++) // 1 ~ n - 1까지 확인
    {
        int tmp = i, value = i;
        while (tmp > 0)
        {
            value += tmp % 10;
            tmp /= 10;
        }

        if (value == n)
            return i;
    }

    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", decomp(n));
    return 0;
}