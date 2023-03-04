/**
 * @file 03. ATM.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-09 20:22:05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int atm(int num)
{
    vector<int> person(num, 0);
    for (int i = 0; i < num; i++)
        cin >> person[i];

    sort(person.begin(), person.end()); // 가장 시간이 적게 드는 사람부터 뽑는게 가장 빠르다

    int time = 0;
    for (int i = 0; i < num; i++)
        time += person[i] * (num - i); // 뒷사람은 앞사람이 끝날 때까지 기다려야 한다

    return time;
}

int main()
{
    int num;
    cin >> num;
    cout << atm(num);
    return 0;
}