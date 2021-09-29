/**
 * @file 05. sort inside.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-26 11:44:16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>

bool desc(int a, int b) // 내림차순을 위한 함수
{
    return a > b;
}

int main()
{
    // 입출력 시간 줄이기
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int size;
    std::string numbers;
    std::cin >> numbers;
    size = numbers.length();

    int number[size];
    for (int i = 0; i < size; i++)
        number[i] = numbers[i] - '0';

    std::sort(number, number + size, desc);
    for (int i = 0; i < size; i++)
        std::cout << number[i];
    return 0;
}