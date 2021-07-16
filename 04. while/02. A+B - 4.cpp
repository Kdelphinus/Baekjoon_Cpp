/**
 * @file 02. A+B - 4.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-16 21:10:33
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int a, b;
    while (std::cin >> a >> b) // 입력이 있으면 true, 없으면 false
        std::cout << a + b << std::endl;
    return 0;
}