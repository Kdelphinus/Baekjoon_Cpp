/**
 * @file 08. start and link.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-03 17:06:17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num, min_diff = 1000000000;
int check[9];
vector<int> start;
vector<vector<int>> football_stat(20, vector<int>(20, 0));

void combination(int n, int m)
{
    if (start.size() == m) // start팀이 완성됐다면
    {
        int start_stat = 0, link_stat = 0; // 두 팀의 스탯을 저장할 변수
        vector<int> link;                  // link팀
        for (int i = 0; i < n; i++)
        {
            if (find(start.begin(), start.end(), i) == start.end()) // start팀에 들어가지 않은 선수들을 link팀에 배정
                link.push_back(i);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++) // 두 팀의 스탯을 각각 더함
            {
                start_stat += football_stat[start[i]][start[j]];
                link_stat += football_stat[link[i]][link[j]];
            }
        }

        int diff;
        diff = abs(start_stat - link_stat); // 두 팀의 스탯차이를 절댓값으로 저장
        if (min_diff > diff)                // 최소 차이보다 더 작다면
            min_diff = diff;                // 최소 차이를 최신화

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (start.size() == 0 && check[i] == 0) // 처음 넣는 선수면
        {
            start.push_back(i); // 선수를 start팀에 넣고
            check[i] = 1;       // 선수가 팀에 들어갔음을 표시
            combination(n, m);  // 다음 선수를 넣으러 이동
            start.pop_back();   // 팀을 다 짰다면 다시 선수를 뺌
            check[i] = 0;       // 팀이 없음을 표시
        }
        else if (start.back() < i && check[i] == 0) // 이미 들어간 수보다 큰 수만 들어갈 수 있다(중복방지, 선수는 차례대로 0부터 번호가 주어짐)
        {
            start.push_back(i); // 선수를 start팀에 넣고
            check[i] = 1;       // 선수가 팀에 들어갔음을 표시
            combination(n, m);  // 다음 선수를 넣으러 이동
            start.pop_back();   // 팀을 다 짰다면 선수를 뺌
            check[i] = 0;       // 팀이 없음을 표시
        }
    }
}

int main()
{
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            int tmp;
            cin >> tmp;
            football_stat[i][j] = tmp;
        }
    }

    combination(num, num / 2); // 2팀으로 나누므로 절반씩 나눔
    cout << min_diff;

    return 0;
}