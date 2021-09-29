/**
 * @file 08. dial.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-20 22:28:36
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int time = 0;
    std::string dial;
    std::cin >> dial;
    for (int i = 0; i < dial.length(); i++)
    {
        if (dial[i] <= 'C')
            time += 3;
        else if (dial[i] <= 'F')
            time += 4;
        else if (dial[i] <= 'I')
            time += 5;
        else if (dial[i] <= 'L')
            time += 6;
        else if (dial[i] <= 'O')
            time += 7;
        else if (dial[i] <= 'S')
            time += 8;
        else if (dial[i] <= 'V')
            time += 9;
        else if (dial[i] <= 'Z')
            time += 10;
    }

    std::cout << time;
    return 0;
}