/**
 * @file 03. find alphabet.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-20 21:48:06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;

    int alphabet[26], idx;
    for (int i = 0; i < 26; i++)
        alphabet[i] = -1;

    for (int i = 0; i < s.length(); i++)
    {
        idx = s[i] - 'a';
        if (alphabet[idx] == -1)
            alphabet[idx] = i;
    }

    for (int i = 0; i < 26; i++)
        std::cout << alphabet[i] << " ";

    return 0;
}