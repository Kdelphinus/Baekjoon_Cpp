/**
 * @file the number and addition of divisor.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief Monthly Code Challenge Season 2
 * @date 2021-11-09 22:26:45
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <cmath>
#include <vector>

using namespace std;

int solution(int left, int right)
{
    int answer = 0;

    for (int i = left; i <= right; i++)
    {
        int tmp = pow(i, 0.5);

        if (tmp * tmp == i)
            answer -= i;
        else
            answer += i;
    }

    return answer;
}