/**
 * @file 02. max.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-17 15:27:13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int tmp, max = 1, index;
    for (int i = 1; i <= 9; i++)
    {
        std::cin >> tmp;
        if (tmp > max)
        {
            max = tmp;
            index = i;
        }
    }

    std::cout << max << std::endl
              << index;
    return 0;
}