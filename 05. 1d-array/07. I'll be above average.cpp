/**
 * @file 07. I'll be above average.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-17 16:20:35
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int num, cnt = 0;
        double mean = 0;
        std::cin >> num;

        int scores[num];
        for (int i = 0; i < num; i++)
        {
            std::cin >> scores[i];
            mean += scores[i];
        }

        mean /= num;
        for (int i = 0; i < num; i++)
        {
            if (mean < scores[i])
                cnt++;
        }

        std::cout << std::fixed;                                    // �Ҽ� ��� �ڸ����� ����
        std::cout.precision(3);                                     // 3�ڸ������� ���
        std::cout << (double)(cnt) / num * 100 << "%" << std::endl; // �Ǽ������� �ٲٱ� ���� cnt�� double�� �ٲ�
    }
    return 0;
}