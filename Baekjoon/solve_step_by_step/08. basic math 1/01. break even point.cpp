/**
 * @file 01. break even point.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-21 23:30:44
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int fixed, change, price;
    std::cin >> fixed >> change >> price;
    // n(손익분기점을 넘는 판매 대수) > fix / (price - change)

    if (price <= change)
        std::cout << -1;
    else
        std::cout << fixed / (price - change) + 1;
    return 0;
}