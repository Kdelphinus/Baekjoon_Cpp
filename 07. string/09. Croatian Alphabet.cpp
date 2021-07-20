/**
 * @file 09. Croatian Alphabet.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-21 00:49:17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    std::string cro;
    std::cin >> cro;

    int words = cro.length();
    for (int i = 0; i < cro.length(); i++)
    {
        if (cro[i] == '=')
        {
            words--;
            if (i - 2 >= 0 && cro[i - 1] == 'z' && cro[i - 2] == 'd')
                words--;
        }
        else if (cro[i] == '-')
            words--;
        else if (cro[i] == 'j')
        {
            if (i - 1 >= 0 && (cro[i - 1] == 'l' || cro[i - 1] == 'n'))
                words--;
        }
    }

    std::cout << words;
    return 0;
}