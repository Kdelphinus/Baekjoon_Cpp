/**
 * @file 02. honeycomb.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-21 23:35:47
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int n, line = 1, cnt = 1, tmp = 6;
    std::cin >> n;

    while (n > line)
    {
        cnt++;
        line += tmp;
        tmp += 6;
    }

    std::cout << cnt;
    return 0;
}