/**
 * @file 04. snail wants to climb.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-23 21:28:11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cmath>

int snail(int up, int down, int goal)
{
    if (up >= goal) // �� ���� �ö� �� ������ �Ϸ�
        return 1;

    int day_up;
    day_up = up - down; // �Ϸ絿�� �ö󰬴ٰ� �������� �Ÿ�

    // �������� ������ �ö󰡱⿡ �Ϸ縦 ���Ѵ�
    if ((goal - up) % day_up) // �Ϸ翡 �ö� �� �ִ� �Ÿ��� �ö󰡴� �Ÿ��� ����� �ƴϸ� �Ϸ縦 �� �ö󰡾� �Ѵ�
        return (goal - up) / day_up + 2;
    else // �Ϸ翡 �ö� �� �ִ� �Ÿ��� �ö󰡴� �Ÿ��� ����̸� ���� ������ �ʴ´�
        return (goal - up) / day_up + 1;
}

int main()
{
    int up, down, goal;
    std::cin >> up >> down >> goal;
    std::cout << snail(up, down, goal);
    return 0;
}