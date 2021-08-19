/**
 * @file 06. rotating queue.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-19 21:52:58
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

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
        if (target[idx] == dq.front()) // ���� ���� ���� ���� �տ� ������
            dq.pop_front();
        else // �ƴ϶��
        {
            target_idx = find(dq.begin(), dq.end(), target[idx]) - dq.begin(); // ���� ���� ��ġ
            size = dq.size();                                                  // ���� ���� ũ��
            if (size / 2 >= target_idx)                                        // ���� ���� ���� �߰��̰ų� ���ʿ� �ִٸ�
            {
                while (1) // ���� ������ ���� ���� �ڷ� �Ѱ��ش�
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
            else // ���� ���� �߰����� �����ʿ� �ִٸ�
            {
                while (1) // ���� ������ ���� ���� ������ �Ѱ��ش�
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