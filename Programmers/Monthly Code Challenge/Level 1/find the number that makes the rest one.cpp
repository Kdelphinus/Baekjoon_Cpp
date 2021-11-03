/**
 * @file find the number that makes the rest one.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief Monthly Code Challenge Season 3
 * @date 2021-11-03 18:54:49
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 1)
            return i;
    }
}