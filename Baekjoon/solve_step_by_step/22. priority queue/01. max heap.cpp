/**
 * @file 01. max heap.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-08 22:58:00
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
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int num, tmp;
    cin >> num;

    priority_queue<int, vector<int>> q;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        if (tmp == 0)
        {
            if (q.empty())
                cout << 0 << '\n';
            else
            {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else
            q.push(tmp);
    }

    return 0;
}