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

        if (min_q.size() > max_q.size()) // max_q에 숫자가 들어가야 할 때
        {
            if (tmp < min_q.top()) // tmp가 min_q에 들어가야 할 때
            {
                min_q.push(tmp);         // min_q에 tmp를 넣고
                max_q.push(min_q.top()); // min_q 중 최댓값을 max_q에 넣은 뒤
                min_q.pop();             // min_q의 최댓값을 뺀다
            }
            else // tmp가 max_q에 들어가야 할 때
                max_q.push(tmp);
        }
        else // min_q에 숫자가 들어가야 할 때
        {
            if (min_q.empty()) // 처음
                min_q.push(tmp);
            else if (tmp > max_q.top()) // tmp가 max_q에 들어가야 할 때
            {
                max_q.push(tmp);         // tmp를 max_q에 넣고
                min_q.push(max_q.top()); // min_q에 max_q의 최솟값을 넣은 뒤
                max_q.pop();             // max_q의 최솟값을 뺀다
            }
            else // tmp가 min_q에 들어가야 할 때
                min_q.push(tmp);
        }
        cout << min_q.top() << '\n';
    }
    return 0;
}