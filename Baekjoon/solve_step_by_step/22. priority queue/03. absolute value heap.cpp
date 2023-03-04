/**
 * @file 03. absolute value heap.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-09 18:15:01
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

    priority_queue<int, vector<int>> minus_q;              // 음수들의 최소힙
    priority_queue<int, vector<int>, greater<int>> plus_q; // 양수들의 최대힙
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        if (tmp > 0) // 양수일 때
            plus_q.push(tmp);
        else if (tmp < 0) // 음수일 때
            minus_q.push(tmp);
        else
        {
            if (minus_q.empty() && plus_q.empty()) // 두 개의 힙이 모두 비어있을 때
                cout << 0 << '\n';
            else if (minus_q.empty()) // 음수힙만 비어있을 때
            {
                cout << plus_q.top() << '\n';
                plus_q.pop();
            }
            else if (plus_q.empty()) // 양수힙만 비어있을 때
            {
                cout << minus_q.top() << '\n';
                minus_q.pop();
            }
            else
            {
                if (abs(minus_q.top()) > plus_q.top()) // 양수힙의 절댓값 < 음수힙의 절댓값
                {
                    cout << plus_q.top() << '\n';
                    plus_q.pop();
                }
                else // 양수힙의 절댓값 >= 음수힙의 절댓값
                {
                    cout << minus_q.top() << '\n';
                    minus_q.pop();
                }
            }
        }
    }
    return 0;
}
