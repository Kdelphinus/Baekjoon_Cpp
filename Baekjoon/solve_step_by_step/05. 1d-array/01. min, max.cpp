/**
 * @file 01. min, max.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-17 15:16:07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int n, min = 1000000, max = -1000000;
    int num;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> num;
        if (min > num)
            min = num;
        if (max < num)
            max = num;
    }

    std::cout << min << " " << max;
    return 0;
}