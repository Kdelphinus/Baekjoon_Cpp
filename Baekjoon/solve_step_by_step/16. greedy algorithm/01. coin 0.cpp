/**
 * @file 01. coin 0.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-09 19:50:18
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

int coin(int num, int goal)
{
    int cnt = 0;
    vector<int> coins_type(num, 0);
    for (int i = 0; i < num; i++)
        cin >> coins_type[i];

    num--;
    while (goal > 0)
    {
        cnt += goal / coins_type[num];
        goal %= coins_type[num--];
    }

    return cnt;
}

int main()
{
    int num, goal;
    cin >> num >> goal;
    cout << coin(num, goal);
    return 0;
}