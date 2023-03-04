/**
 * @file 08. hide and seek.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief
 * @date 2021-10-14 19:01:51
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <queue>
using namespace std;

int dot[100001]; // �� ��ġ�� Ž���ߴ��� Ȯ���� ����Ʈ

int main()
{
    int subin, sister;
    cin >> subin >> sister; // ����� ������ ��ġ

    if (subin == sister) // ���� ��ġ�� �ٷ� ã�´�
    {
        cout << 0;
        return 0;
    }

    queue<int> q;
    int now, cnt = 0;            // ���� ��ġ, ���� ��ġ���� �Ѿ �� �ִ� ��� �� Ȯ���� ����� ��
    int second = 0, sec_cnt = 1; // ������ �ð�, ���� �ð��� �� �� �ִ� ��ġ�� ��
    q.push(subin);
    dot[subin] = 1;

    while (!q.empty())
    {
        if (cnt == sec_cnt)
        {
            second++;
            cnt = 0;
            sec_cnt = q.size();
        }

        now = q.front();
        q.pop();

        if (now - 1 == sister || now + 1 == sister || now * 2 == sister) //  ���� ��ҿ� �� �� �ִٸ�
        {
            cout << second + 1; // ���� �ð��� 1�ʸ� ���ϰ� ����
            break;
        }

        if (now - 1 >= 0 && dot[now - 1] == 0)
        {
            dot[now - 1] = 1;
            q.push(now - 1);
        }
        if (now + 1 <= 100000 && dot[now + 1] == 0)
        {
            dot[now + 1] = 1;
            q.push(now + 1);
        }
        if (now * 2 <= 100000 && dot[now * 2] == 0)
        {
            dot[now * 2] = 1;
            q.push(now * 2);
        }
        cnt++;
    }
    return 0;
}