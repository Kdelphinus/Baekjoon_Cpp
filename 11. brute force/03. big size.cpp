/**
 * @file 03. big size.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-25 17:23:30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

int size[51][3];

void size_rank(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i == j) // ���� 0�̱⿡ �ڱ� �ڽ����� 1�߰�
                size[i][2]++;
            else if (size[i][0] < size[j][0] && size[i][1] < size[j][1]) // �ٸ� ������� ��ġ�� �۴ٸ� 1�߰�
                size[i][2]++;
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
        scanf("%d %d", &size[i][0], &size[i][1]);

    size_rank(num);
    for (int i = 0; i < num; i++)
        printf("%d ", size[i][2]);

    return 0;
}