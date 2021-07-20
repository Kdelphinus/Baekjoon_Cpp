/**
 * @file 05. studying vocabulary.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-20 22:01:19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int alphabet[26] = {0}, idx, max = 0;
    char alpha;
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] - 'a' >= 0 && s[i] - 'a' < 26)
        {
            idx = s[i] - 'a';
            alphabet[idx]++;
        }
        else
        {
            idx = s[i] - 'A';
            alphabet[idx]++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] > max)
        {
            max = alphabet[i];
            alpha = i + 'A';
        }
        else if (alphabet[i] == max)
            alpha = '?';
    }

    std::cout << alpha;

    return 0;
}