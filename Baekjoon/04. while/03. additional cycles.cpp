/**
 * @file 03. additional cycles.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-16 21:21:58
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int n, tmp = 0, goal, cnt = 0;
    std::cin >> n;

    goal = n;

    while (1)
    {
        tmp = n / 10 + n % 10;

        if (tmp >= 10)
            tmp %= 10;

        n = ((n % 10) * 10) + tmp;
        cnt++;

        if (n == goal)
        {
            std::cout << cnt;
            break;
        }
    }

    return 0;
}