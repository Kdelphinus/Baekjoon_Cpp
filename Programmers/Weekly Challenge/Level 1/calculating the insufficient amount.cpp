/**
 * @file calculating the insufficient amount.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief Weekly Challenge
 * @date 2021-11-03 18:57:26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    long long sum = 0;

    for (int i = 1; i <= count; i++)
        sum += price * i;

    long long answer = sum - money;

    return max(answer, 0ll);
}