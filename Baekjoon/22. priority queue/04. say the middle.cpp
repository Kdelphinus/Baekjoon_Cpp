#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int num, tmp;
    cin >> num;

    priority_queue<int, vector<int>> min_q;
    priority_queue<int, vector<int>, greater<int>> max_q;

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;

        if (min_q.size() > max_q.size()) // max_q�� ���ڰ� ���� �� ��
        {
            if (tmp < min_q.top()) // tmp�� min_q�� ���� �� ��
            {
                min_q.push(tmp);         // min_q�� tmp�� �ְ�
                max_q.push(min_q.top()); // min_q �� �ִ��� max_q�� ���� ��
                min_q.pop();             // min_q�� �ִ��� ����
            }
            else // tmp�� max_q�� ���� �� ��
                max_q.push(tmp);
        }
        else // min_q�� ���ڰ� ���� �� ��
        {
            if (min_q.empty()) // ó��
                min_q.push(tmp);
            else if (tmp > max_q.top()) // tmp�� max_q�� ���� �� ��
            {
                max_q.push(tmp);         // tmp�� max_q�� �ְ�
                min_q.push(max_q.top()); // min_q�� max_q�� �ּڰ��� ���� ��
                max_q.pop();             // max_q�� �ּڰ��� ����
            }
            else // tmp�� min_q�� ���� �� ��
                min_q.push(tmp);
        }
        cout << min_q.top() << '\n';
    }
    return 0;
}