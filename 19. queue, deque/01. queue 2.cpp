/**
 * @file 01. queue 2.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-18 16:14:11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num, number;
    string order;
    queue<int> q;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> order;

        if (order == "push")
        {
            cin >> number;
            q.push(number);
        }
        else if (order == "pop")
        {
            if (q.empty())
                cout << -1 << "\n";
            else
            {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (order == "size")
            cout << q.size() << '\n';
        else if (order == "empty")
        {
            if (q.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (order == "front")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.front() << '\n';
        }
        else if (order == "back")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.back() << '\n';
        }
        else
            cout << "잘못된 명령어입니다" << '\n';
    }
    return 0;
}