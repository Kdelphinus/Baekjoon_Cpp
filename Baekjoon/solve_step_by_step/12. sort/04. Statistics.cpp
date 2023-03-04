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

int mean(int numbers[], int num) // ������
{
    double sum = 0;
    for (int i = 0; i < num; i++)
        sum += numbers[i];

    return floor(sum / num + 0.5); // ������ �̿��� �ݿø�
}

int median(int numbers[], int num) // �߾Ӱ�
{
    return numbers[num / 2];
}

int mode(int numbers[], int num) // �ֺ�
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

int range(int numbers[], int num) // ����
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

    printf("%d\n", mean(numbers, num));   // ������
    printf("%d\n", median(numbers, num)); // �߾Ӱ�
    printf("%d\n", mode(numbers, num));   // �ֺ�
    printf("%d\n", range(numbers, num));  // ����

    return 0;
}