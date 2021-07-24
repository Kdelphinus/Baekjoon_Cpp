/**
 * @file 06. I'm going to be the head of the women's association.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 13:44:06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int people[15][15];

void apartmant()
{
    int floor = 14, room = 14;
    for (int i = 0; i <= floor; i++)
    {
        for (int j = 1; j <= room; j++)
        {
            if (i == 0)
                people[i][j] = j;
            else if (j == 1)
                people[i][j] = 1;
            else
                people[i][j] = people[i][j - 1] + people[i - 1][j];
        }
    }
}

int main()
{
    int test;
    std::cin >> test;
    apartmant();

    for (int i = 0; i < test; i++)
    {
        int floor, room;
        std::cin >> floor >> room;
        std::cout << people[floor][room] << std::endl;
    }
    return 0;
}