/**
 * @file 01. ASCII.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-20 21:30:39
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    char ch;
    std::cin >> ch;
    std::cout << static_cast<int>(ch); // 형변환을 통한 아스키코드 변환

    return 0;
}