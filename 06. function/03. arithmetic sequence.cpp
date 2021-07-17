/**
 * @file 03. arithmetic sequence.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-17 21:51:06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

bool check(int num) // 한수인지 체크하는 함수
{
    int tmp, diff, flag = 0;

    while (num > 0)
    {
        if (flag == 0) // 일의 자리수
        {
            tmp = num % 10; // 임시 변수에 저장
            num /= 10;
            flag++;
        }
        else if (flag == 1) // 십의 자리수
        {
            diff = tmp - num % 10; // 두 자리수 차이를 저장
            tmp = num % 10;
            num /= 10;
            flag++;
        }
        else // 백의 자리부터 ~
        {
            if (diff != tmp - num % 10) // 원래 차이와 지금 차이가 같지 않다면
            {
                flag = 0; // 한수 아님
                break;
            }
            tmp = num % 10;
            num /= 10;
        }
    }

    if (flag)
        return true;

    return false;
}

int arithmetic_sequence(int num)
{
    if (num <= 99) // 99 이하는 모두 한수이다
        return num;

    int cnt = 99;
    for (int i = 100; i <= num; i++) // 99까지는 모두 한수이므로 100부터 확인
    {
        if (check(i)) // 한수이면 카운트 추가
            cnt++;
    }

    return cnt;
}

int main()
{
    int num;
    std::cin >> num;
    std::cout << arithmetic_sequence(num);

    return 0;
}