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

    priority_queue<int, vector<int>> minus_q;              // �������� �ּ���
    priority_queue<int, vector<int>, greater<int>> plus_q; // ������� �ִ���
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        if (tmp > 0) // ����� ��
            plus_q.push(tmp);
        else if (tmp < 0) // ������ ��
            minus_q.push(tmp);
        else
        {
            if (minus_q.empty() && plus_q.empty()) // �� ���� ���� ��� ������� ��
                cout << 0 << '\n';
            else if (minus_q.empty()) // �������� ������� ��
            {
                cout << plus_q.top() << '\n';
                plus_q.pop();
            }
            else if (plus_q.empty()) // ������� ������� ��
            {
                cout << minus_q.top() << '\n';
                minus_q.pop();
            }
            else
            {
                if (abs(minus_q.top()) > plus_q.top()) // ������� ���� < �������� ����
                {
                    cout << plus_q.top() << '\n';
                    plus_q.pop();
                }
                else // ������� ���� >= �������� ����
                {
                    cout << minus_q.top() << '\n';
                    minus_q.pop();
                }
            }
        }
    }
    return 0;
}
