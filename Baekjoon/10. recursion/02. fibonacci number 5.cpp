/**
 * @file 02. fibonacci number 5.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 20:38:50
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));
    return 0;
}