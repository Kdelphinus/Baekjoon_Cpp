/**
 * @file 11. turret.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 20:26:39
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cmath>

int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int x1, y1, r1, x2, y2, r2;
        float dist;

        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        dist = sqrt(pow(x2 - x1 + 0.0, 2) + pow(y2 - y1 + 0.0, 2));

        if (x1 == x2 && y1 == y2 && r1 == r2)
            printf("-1\n");
        else if (abs(r2 - r1) < dist && dist < r2 + r1)
            printf("2\n");
        else if (abs(r2 - r1) == dist || r2 + r1 == dist)
            printf("1\n");
        else if (abs(r2 - r1) > dist || r2 + r1 < dist)
            printf("0\n");
    }
    return 0;
}