/**
 * @file 03. counting sort.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-26 10:33:46
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int main()
{
    int num;
    int tmp, counting[10001] = {0};
    std::cin >> num;

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &tmp);
        counting[tmp]++;
    }
    for (int i = 1; i <= 10000; i++) // ���� ������ 10,000������ �ڿ����̹Ƿ�
    {
        for (int j = 0; j < counting[i]; j++) // ���ڸ� �� ����� ������ ��� ���
            printf("%d\n", i);
    }
    return 0;
}