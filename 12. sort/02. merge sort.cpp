/**
 * @file 02. merge sort.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief merge sort
 * @date 2021-07-25 18:59:30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int number[1000001];
int b[1000001];

void merge(int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (number[i] < number[j])
            b[k++] = number[i++];
        else
            b[k++] = number[j++];
    }

    while (i <= mid)
        b[k++] = number[i++];
    while (j <= end)
        b[k++] = number[j++];

    k--;
    while (k >= 0)
    {
        number[start + k] = b[k];
        k--;
    }
}

void mergesort(int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergesort(start, mid);
        mergesort(mid + 1, end);
        merge(start, mid, end);
    }
}

int main()
{
    int num;
    std::cin >> num;

    for (int i = 0; i < num; i++)
        std::cin >> number[i];

    mergesort(0, num - 1);

    for (int i = 0; i < num; i++)
        std::cout << number[i] << "\n";
    return 0;
}