/**
 * @file 02. prime number.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 18:55:49
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int isPrime(int a)
{
    if (a == 1)
        return 0;

    if (a == 2)
        return 1;

    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int start, end, sum = 0, min = 0;
    std::cin >> start >> end;

    for (int i = start; i <= end; i++)
    {
        if (isPrime(i))
        {
            sum += i;
            if (min == 0)
                min = i;
        }
    }

    if (sum == 0)
        std::cout << -1;
    else
    {
        std::cout << sum << std::endl
                  << min;
    }
    return 0;
}