/**
 * @file 01. factorial.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 20:35:55
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int factorial(int n)
{
    if (n <= 1)
        return 1;

    return factorial(n - 1) * n;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", factorial(n));
    return 0;
}