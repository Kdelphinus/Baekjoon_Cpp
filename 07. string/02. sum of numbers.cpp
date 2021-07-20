/**
 * @file 02. sum of numbers.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-20 21:36:18
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int n, sum = 0;
    std::cin >> n;

    std::string numbers;
    std::cin >> numbers;

    for (int i = 0; i < n; i++) // 아스키코드로 바뀌기에 숫자로 변환
        sum += static_cast<int>(numbers[i]) - static_cast<int>('0');

    std::cout << sum;
    return 0;
}