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

    priority_queue<int, vector<int>, greater<int>> q;
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