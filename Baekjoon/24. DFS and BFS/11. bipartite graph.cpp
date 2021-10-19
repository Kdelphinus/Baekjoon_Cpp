/**
 * @file 11. bipartite graph.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 이분 그래프의 정의: https://gmlwjd9405.github.io/2018/08/23/algorithm-bipartite-graph.html
 * @date 2021-10-19 22:08:44
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> linked(20001); // 연결된 노드들을 저장할 벡터
int nodes[20001];                  // 노드들의 색을 저장할 배열

bool BFS(int start)
{
    int tmp;
    nodes[start] = 1; // 색을 칠해준다
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        tmp = q.front();
        q.pop();

        for (int i = 0; i < linked[tmp].size(); i++)
        {                                   // 연결된 노드들을 하나씩 확인
            if (nodes[linked[tmp][i]] == 0) // 색이 없는 노드일 때
            {
                nodes[linked[tmp][i]] = -nodes[tmp]; // 현재 노드와 다른 색을 칠하고
                q.push(linked[tmp][i]);              // 탐색 범위에 추가
            }
            else // 색이 있는 노드일 때
            {
                if (nodes[linked[tmp][i]] == nodes[tmp]) // 같은 색이면
                    return false;                        // 이분 그래프가 아니다
            }
        }
    }
    return true; // 모든 탐색이 끝났다면 이분 그래프이다
}

int main()
{
    int test;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        string isTrue = "YES";
        int node_num, linked_num, start, end;
        cin >> node_num >> linked_num;
        for (int j = 0; j < linked_num; j++) // 연결된 노드들 저장
        {
            cin >> start >> end;
            linked[start].push_back(end);
            linked[end].push_back(start);
        }

        for (int n = 1; n <= node_num; n++)
        {
            if (nodes[n] == 0) // 색이 없는 노드일 때
            {
                if (!BFS(n)) // 인접한 노드와 색이 겹치면
                {
                    isTrue = "NO"; // 이분 그래프가 아니다
                    break;
                }
            }
        }
        cout << isTrue << '\n';
        for (int j = 1; j <= node_num; j++)
        {
            nodes[j] = 0;      // 노드의 색 초기화
            linked[j].clear(); // 연결된 노드들 초기화
        }
    }

    return 0;
}