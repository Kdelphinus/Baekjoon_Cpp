/**
 * @file 07. I'll be above average.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-17 16:20:35
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int num, cnt = 0;
        double mean = 0;
        std::cin >> num;

        int scores[num];
        for (int i = 0; i < num; i++)
        {
            std::cin >> scores[i];
            mean += scores[i];
        }

        mean /= num;
        for (int i = 0; i < num; i++)
        {
            if (mean < scores[i])
                cnt++;
        }

        std::cout << std::fixed;                                    // 소수 출력 자릿수를 고정
        std::cout.precision(3);                                     // 3자리까지만 출력
        std::cout << (double)(cnt) / num * 100 << "%" << std::endl; // 실수형으로 바꾸기 위해 cnt를 double로 바꿈
    }
    return 0;
}