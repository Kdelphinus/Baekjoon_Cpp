/**
 * @file 04. Statistics.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-26 11:18:38
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <algorithm>
#include <cmath>

int mean(int numbers[], int num) // 산술평균
{
    double sum = 0;
    for (int i = 0; i < num; i++)
        sum += numbers[i];

    return floor(sum / num + 0.5); // 내림을 이용한 반올림
}

int median(int numbers[], int num) // 중앙값
{
    return numbers[num / 2];
}

int mode(int numbers[], int num) // 최빈값
{
    int counting[8002] = {0};
    for (int i = 0; i < num; i++)
        counting[numbers[i] + 4000]++;

    int max = 0, flag = 0, value;
    for (int i = 0; i <= 8001; i++)
    {
        if (max < counting[i])
        {
            value = i - 4000;
            flag = 1;
            max = counting[i];
        }
        else if (max == counting[i] && flag < 2)
        {
            value = i - 4000;
            flag++;
        }
    }

    return value;
}

int range(int numbers[], int num) // 범위
{
    return numbers[num - 1] - numbers[0];
}

int main()
{
    int num;
    scanf("%d", &num);

    int numbers[num];
    for (int i = 0; i < num; i++)
        scanf("%d", &numbers[i]);

    std::sort(numbers, numbers + num);

    printf("%d\n", mean(numbers, num));   // 산술평균
    printf("%d\n", median(numbers, num)); // 중앙값
    printf("%d\n", mode(numbers, num));   // 최빈값
    printf("%d\n", range(numbers, num));  // 범위

    return 0;
}