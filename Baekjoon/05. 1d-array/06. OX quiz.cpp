/**
 * @file 06. OX quiz.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-17 16:02:06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>

int main()
{
    int t; // test 개수
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int len, bonus = 0, score = 0;
        std::string anw; // 채점 결과를 받음
        std::cin >> anw;
        len = anw.length(); // 채점 결과 길이

        for (int i = 0; i < len; i++)
        {
            if (anw[i] == 'O') // 맞았으면
            {
                score += bonus + 1; // 기본 점수 1점과 보너스 점수를 더해줌
                bonus++;            // 이번 문제를 맞췄기에 보너스 점수 1점 추가
            }
            else           // 틀렸다면
                bonus = 0; // 보너스 점수 초기화
        }
        std::cout << score << std::endl;
    }
    return 0;
}