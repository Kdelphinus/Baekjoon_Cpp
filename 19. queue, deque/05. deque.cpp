/**
 * @file 05. deque.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-18 17:10:41
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num, tmp;
    string order;
    deque<int> dq;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> order;
        if (order == "push_front")
        {
            cin >> tmp;
            dq.push_front(tmp);
        }
        else if (order == "push_back")
        {
            cin >> tmp;
            dq.push_back(tmp);
        }
        else if (order == "pop_front")
        {
            if (dq.empty())
                cout << -1 << '\n';
            else
            {
                tmp = dq.front();
                dq.pop_front();
                cout << tmp << '\n';
            }
        }
        else if (order == "pop_back")
        {
            if (dq.empty())
                cout << -1 << '\n';
            else
            {
                tmp = dq.back();
                dq.pop_back();
                cout << tmp << '\n';
            }
        }
        else if (order == "size")
            cout << dq.size() << '\n';
        else if (order == "empty")
        {
            if (dq.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (order == "front")
        {
            if (dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.front() << '\n';
        }
        else if (order == "back")
        {
            if (dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.back() << '\n';
        }
        else
            cout << "잘못된 명령어입니다" << '\n';
    }
    return 0;
}