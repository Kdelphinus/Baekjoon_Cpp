/**
 * @file flip the 3-digit rule.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief Monthly Code Challenge Season 1
 * @date 2021-11-08 22:43:34
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 0, power = 0;
    string num = "";

    // 3진법으로 변환 뒤, 뒤집은 형태
    while (n > 0)
    {
        num += to_string(n % 3);
        n /= 3;
    }

    // 다시 10진법으로 변환
    for (int i = num.size() - 1; i >= 0; i--)
    {
        answer += (num[i] - '0') * pow(3, power);
        power++;
    }

    return answer;
}