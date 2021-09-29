/**
 * @file 01. A+B - 5.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-16 21:07:19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    while (1)
    {
        int a, b;
        std::cin >> a >> b;

        if (a == 0 && b == 0)
            break;
        std::cout << a + b << std::endl;
    }

    return 0;
}