/**
 * @file 02. card2.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-18 16:24:58
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <queue>

using namespace std;

int card(int num)
{
    int tmp;
    queue<int> q;
    for (int i = 1; i <= num; i++)
        q.push(i);

    while (q.size() > 1) // 하나 남을 때까지 반복
    {
        // 앞 장을 빼고
        q.pop();

        // 앞 장을 뒤로 옮긴다
        tmp = q.front();
        q.pop();
        q.push(tmp);
    }

    return q.front();
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num;
    cin >> num;
    cout << card(num);
    return 0;
}