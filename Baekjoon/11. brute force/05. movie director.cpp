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
            if (tmp % 10 == 6) // 6�� ������ üũ
                check++;
            else // 6�� �ƴϸ� üũ�Ѱ� �ʱ�ȭ
                check = 0;

            if (check == 3) // 6�� ���� �� �� ������ ����
            {
                cnt++;
                break;
            }

            tmp /= 10;
        }

        if (cnt == num) // ���� �ø��� ������ 666�� ���� ������ ���ٸ�
        {
            std::cout << number;
            break;
        }
        else
            number++;
    }
    return 0;
}