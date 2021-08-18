#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int rotating(int num, int target_num)
{
    int cnt = 0, target_idx, tmp, size;
    deque<int> dq;
    vector<int> target(target_num, 0);

    for (int i = 0; i < target_num; i++)
        cin >> target[i];
    for (int i = 1; i <= num; i++)
        dq.push_back(i);

    for (int idx = 0; idx < target_num; idx++)
    {
        if (target[idx] == dq.front())
            dq.pop_front();
        else
        {
            target_idx = lower_bound(dq.begin(), dq.end(), target[idx]) - dq.begin();
            size = dq.size();
            if (size / 2 >= target_idx)
            {
                while (1)
                {
                    if (target[idx] == dq.front())
                    {
                        dq.pop_front();
                        break;
                    }
                    tmp = dq.front();
                    dq.pop_front();
                    dq.push_back(tmp);
                    cnt++;
                }
            }
            else
            {
                while (1)
                {
                    if (target[idx] == dq.front())
                    {
                        dq.pop_front();
                        break;
                    }
                    tmp = dq.back();
                    dq.pop_back();
                    dq.push_front(tmp);
                    cnt++;
                }
            }
        }
        idx++;
    }

    return cnt;
}

int main()
{
    int num, target_num;
    cin >> num >> target_num;
    cout << rotating(num, target_num);
    return 0;
}