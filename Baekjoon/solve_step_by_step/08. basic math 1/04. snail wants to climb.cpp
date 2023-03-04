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
    if (up >= goal) // 한 번에 올라갈 수 있으면 하루
        return 1;

    int day_up;
    day_up = up - down; // 하루동안 올라갔다가 내려오는 거리

    // 마지막은 낮에만 올라가기에 하루를 더한다
    if ((goal - up) % day_up) // 하루에 올라갈 수 있는 거리가 올라가는 거리의 약수가 아니면 하루를 더 올라가야 한다
        return (goal - up) / day_up + 2;
    else // 하루에 올라갈 수 있는 거리가 올라가는 거리의 약수이면 굳이 더하지 않는다
        return (goal - up) / day_up + 1;
}

int main()
{
    int up, down, goal;
    std::cin >> up >> down >> goal;
    std::cout << snail(up, down, goal);
    return 0;
}