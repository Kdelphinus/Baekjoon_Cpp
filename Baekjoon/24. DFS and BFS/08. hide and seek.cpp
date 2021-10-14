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

int dot[100001]; // 그 위치를 탐색했는지 확인할 리스트

int main()
{
    int subin, sister;
    cin >> subin >> sister; // 수빈과 동생의 위치

    if (subin == sister) // 같은 위치면 바로 찾는다
    {
        cout << 0;
        return 0;
    }

    queue<int> q;
    int now, cnt = 0;            // 현재 위치, 현재 위치에서 넘어갈 수 있는 장소 중 확인한 장소의 수
    int second = 0, sec_cnt = 1; // 지나간 시간, 현재 시간에 갈 수 있는 위치의 수
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

        if (now - 1 == sister || now + 1 == sister || now * 2 == sister) //  다음 장소에 갈 수 있다면
        {
            cout << second + 1; // 현재 시간에 1초를 더하고 종료
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