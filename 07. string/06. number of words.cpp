/**
 * @file 06. number of words.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-20 22:09:40
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>

int main()
{
    int cnt = 0;
    std::string s;
    std::getline(std::cin, s);    // 공백있는 문자열 받기
    if (s[s.length() - 1] != ' ') // 맨 뒤가 공백이 아니면
        s.append(" ");            // 가장 뒤에 있는 단어도 추가하기 위해 공백 추가

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ') // 공백이 나올 때마다 단어 개수 추가
        {
            if (i > 0) // 공백이 맨 앞이면 제외
                cnt++;
        }
    }

    std::cout << cnt;

    return 0;
}