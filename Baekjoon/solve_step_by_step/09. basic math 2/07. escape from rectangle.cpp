/**
 * @file 07. escape from rectangle.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 19:54:53
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int min(int a, int b)
{
    if (a > b)
        return b;

    return a;
}

int main()
{
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    printf("%d", min(min(min(w - x, x), h - y), y));
    return 0;
}