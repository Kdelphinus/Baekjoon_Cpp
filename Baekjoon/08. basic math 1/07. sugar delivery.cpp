/**
 * @file 07. sugar delivery.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 14:01:16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int goal, five;
    std::cin >> goal;

    five = goal / 5;
    if (goal % 5 == 0)
        std::cout << five;
    else
    {
        while (1)
        {
            if ((goal - 5 * five) % 3 == 0)
            {
                std::cout << five + ((goal - 5 * five) / 3);
                break;
            }
            five--;
            if (five <= 0)
            {
                if (goal % 3 == 0)
                    std::cout << goal / 3;
                else
                    std::cout << -1;
                break;
            }
        }
    }
    return 0;
}