/**
 * @file 03. prime factorization.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 18:59:13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int n, i = 2;
    std::cin >> n;

    if (n > 1)
    {
        while (n > 1)
        {
            if (n % i)
                i++;
            else
            {
                std::cout << i << std::endl;
                n /= i;
            }
        }
    }

    return 0;
}