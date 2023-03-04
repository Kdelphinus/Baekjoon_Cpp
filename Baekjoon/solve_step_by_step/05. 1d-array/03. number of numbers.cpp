/**
 * @file 03. number of numbers.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-17 15:31:49
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int a, b, c, result;
    int num[10] = {0};
    std::cin >> a >> b >> c;
    result = a * b * c;

    while (result)
    {
        num[result % 10]++;
        result /= 10;
    }

    for (int i = 0; i < 10; i++)
        std::cout << num[i] << std::endl;

    return 0;
}