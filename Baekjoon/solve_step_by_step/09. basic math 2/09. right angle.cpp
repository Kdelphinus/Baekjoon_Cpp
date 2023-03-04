/**
 * @file 09. right angle.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 20:04:02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    while (1)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (a == 0 && b == 0 && c == 0)
            break;

        if (max(max(a, b), c) == a)
        {
            int tmp;
            tmp = a;
            a = c;
            c = tmp;
        }
        else if (max(max(a, b), c) == b)
        {
            int tmp;
            tmp = b;
            b = c;
            c = tmp;
        }

        if (a * a + b * b == c * c)
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}