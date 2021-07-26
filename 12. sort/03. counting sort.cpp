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
    for (int i = 1; i <= 10000; i++) // 숫자 범위가 10,000이하의 자연수이므로
    {
        for (int j = 0; j < counting[i]; j++) // 숫자를 다 출력할 때까지 계속 출력
            printf("%d\n", i);
    }
    return 0;
}