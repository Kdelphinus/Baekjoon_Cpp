/**
 * @file 03. find fraction.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-21 23:43:14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int n, denominator = 1, numerator = 1;
    std::cin >> n;

    for (int i = 1; i < n; i++)
    {
        if ((denominator + numerator) % 2 == 0)
        {
            if (numerator > 1)
                numerator--;
            denominator++;
        }
        else
        {
            if (denominator > 1)
                denominator--;
            numerator++;
        }
    }

    std::cout << numerator << "/" << denominator;

    return 0;
}