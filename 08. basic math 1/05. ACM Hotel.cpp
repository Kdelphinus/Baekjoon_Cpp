/**
 * @file 05. ACM Hotel.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 13:33:13
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
        int height, width, order;
        std::cin >> height >> width >> order;

        int floor, room;
        room = (order - 1) / height + 1;
        floor = order % height;
        if (floor == 0)
            floor = height;
        if (room < 10)
            std::cout << floor << "0" << room << std::endl;
        else
            std::cout << floor << room << std::endl;
    }
    return 0;
}