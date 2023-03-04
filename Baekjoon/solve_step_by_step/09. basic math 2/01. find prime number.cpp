/**
 * @file 01. find prime number.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 18:50:25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int n, cnt = 0;
    std::cin >> n;

    for (int j = 0; j < n; j++)
    {
        int num, i = 2;
        std::cin >> num;

        if (num == 1)
            continue;

        if (num == 2)
        {
            cnt++;
            continue;
        }

        while (1)
        {
            if (num % i == 0)
                break;

            i++;

            if (num == i)
            {
                cnt++;
                break;
            }
        }
    }

    std::cout << cnt;
    return 0;
}