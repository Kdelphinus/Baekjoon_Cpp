/**
 * @file 07. constant.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-20 22:23:53
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    std::string a, b;
    std::cin >> a >> b;
    char tmp;

    tmp = a[0];
    a[0] = a[2];
    a[2] = tmp;

    tmp = b[0];
    b[0] = b[2];
    b[2] = tmp;

    if (a > b)
        std::cout << a;
    else
        std::cout << b;
    return 0;
}