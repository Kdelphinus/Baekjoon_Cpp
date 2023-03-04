/**
 * @file 05. mean.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-17 15:49:10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    double mean = 0, max = 0;
    double scores[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> scores[i];
        if (scores[i] > max)
            max = scores[i];
    }

    for (int i = 0; i < n; i++)
        mean += scores[i] / max * 100;

    mean /= n;
    std::cout << mean;

    return 0;
}