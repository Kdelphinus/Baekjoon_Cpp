/**
 * @file 04. remainder.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-17 15:36:08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int num, cnt = 0;
    int reaminder[42] = {0};
    for (int i = 0; i < 10; i++)
    {
        std::cin >> num;
        if (reaminder[num % 42] == 0)
        {
            reaminder[num % 42]++;
            cnt++;
        }
    }

    std::cout << cnt;

    return 0;
}