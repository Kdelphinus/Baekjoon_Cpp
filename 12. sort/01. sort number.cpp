/**
 * @file 01. sort number.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-25 18:33:46
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <algorithm> // sort함수 불러오기

int main()
{
    int num;
    std::cin >> num;

    int numbers[num];
    for (int i = 0; i < num; i++)
        std::cin >> numbers[i];

    std::sort(numbers, numbers + num); // c++에 내장된 정렬 함수
    for (int i = 0; i < num; i++)
        std::cout << numbers[i] << "\n";

    return 0;
}