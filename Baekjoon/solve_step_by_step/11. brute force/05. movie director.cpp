/**
 * @file 05. movie director.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-25 17:59:58
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int num, number = 666, cnt = 0;
    std::cin >> num;

    while (1)
    {
        int check = 0, tmp = number;
        while (tmp > 0)
        {
            if (tmp % 10 == 6) // 6이 나오면 체크
                check++;
            else // 6이 아니면 체크한거 초기화
                check = 0;

            if (check == 3) // 6이 연속 세 번 나오면 종료
            {
                cnt++;
                break;
            }

            tmp /= 10;
        }

        if (cnt == num) // 만약 시리즈 순서와 666이 나온 순서가 같다면
        {
            std::cout << number;
            break;
        }
        else
            number++;
    }
    return 0;
}