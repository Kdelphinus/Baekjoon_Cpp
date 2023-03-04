/**
 * @file 10.  group word checkers.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-21 00:54:37
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int test, cnt = 0;
    std::cin >> test;

    for (int i = 0; i < test; i++)
    {
        bool flag = true;
        int alpha[26] = {0};
        std::string s;
        std::cin >> s;
        char tmp = s[0];

        for (int j = 1; j < s.length(); j++)
        {
            if (tmp != s[j])
            {
                if (alpha[s[j] - 'a'])
                {
                    flag = false;
                    break;
                }
                alpha[tmp - 'a']++;
                tmp = s[j];
            }
        }

        if (flag)
            cnt++;
    }

    std::cout << cnt;
    return 0;
}