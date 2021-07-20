/**
 * @file 04. repeat string.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-20 21:52:10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int test;
    std::cin >> test;

    for (int i = 0; i < test; i++)
    {
        int repeat;
        std::string s;
        std::cin >> repeat >> s;

        for (int j = 0; j < s.length(); j++)
        {
            for (int k = 0; k < repeat; k++)
                std::cout << s[j];
        }

        std::cout << std::endl;
    }

    return 0;
}