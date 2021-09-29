/**
 * @file 02. self number.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-17 21:27:13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int numbers[10001];

void self_number(int num)
{
    int tmp;
    tmp = num;      // 받은 수를 복사하고
    while (tmp > 0) // 각 자릿수를 받은 수에 더한다
    {
        num += tmp % 10;
        tmp /= 10;
    }

    numbers[num]++; // 이 숫자를 셀프 넘버가 아니라고 표시하고

    if (num <= 10000)     // 범위를 벗어나지 않는 수가 만들어졌다면
        self_number(num); // 셀프 넘버가 아닌 수를 또 찾는다
}

int main()
{
    for (int i = 1; i <= 10000; i++) // 범위 안에 수를 확인
    {
        if (numbers[i] == 0) // 셀프 넘버가 아니면
        {
            std::cout << i << std::endl; // 이 수를 출력하고
            self_number(i);              // 이 수로 만들수 있는 모든 셀프 넘버가 아닌 것을 찾는다
        }
    }

    return 0;
}