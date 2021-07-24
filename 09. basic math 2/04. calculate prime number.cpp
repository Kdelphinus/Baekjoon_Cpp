/**
 * @file 04. calculate prime number.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 19:10:30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cmath>

int main()
{
    int start, end, tmp;
    std::cin >> start >> end;

    int numbers[end + 1] = {0};
    numbers[0] = 1;
    numbers[1] = 1;
    tmp = sqrt(end);

    for (int i = 2; i <= tmp; i++) // 에라토스테네스의 체
    {
        if (numbers[i] == 0)
        {
            for (int j = i + i; j <= end; j += i)
                numbers[j] = 1;
        }
    }

    for (int i = start; i <= end; i++)
    {
        if (numbers[i] == 0)
            std::cout << i << "\n"; // std::endl은 생각보다 시간을 아주 많이 잡아먹는다
    }

    return 0;
}