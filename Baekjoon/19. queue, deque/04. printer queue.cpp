/**
 * @file 04. printer queue.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-18 16:58:50
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b) // 내림차순을 위한 함수
{
    return a > b;
}

int printer(int num, int check)
{
    int tmp, idx = 0, cnt = 1;
    queue<int> q;
    vector<int> value;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        q.push(tmp);
        value.push_back(tmp);
    }

    sort(value.begin(), value.end(), desc); // 중요도 순으로 정렬

    while (1)
    {
        if (q.front() == value[idx]) // 현재 뽑을 문서가 맨 앞에 있다면
        {
            if (check == 0) // 근데 그것이 우리가 알고 싶은 것이라면
                return cnt; // 뽑는 순서를 리턴

            // 우리가 알고 싶은 것이 아니라면
            q.pop(); // 문서를 출력하고
            idx++;   // 다음으로 뽑을 문서로 이동
            check--; // 우리가 알고 싶은 문서의 위치 업데이트
            cnt++;   // 뽑은 횟수 추가
        }
        else // 현재 뽑을 문서가 아니라면
        {
            tmp = q.front(); // 앞에 있는 문서를
            q.pop();         // 빼서
            q.push(tmp);     // 뒤로 옮긴다

            if (check == 0)           // 맨 앞의 문서가 우리가 원한던 문서면
                check = q.size() - 1; // 맨 뒤에 위치한 것으로 위치를 저장하고
            else                      // 아니라면
                check--;              // 앞으로 하나 옮긴다
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        int num, check;
        cin >> num >> check;
        cout << printer(num, check) << '\n';
    }
    return 0;
}