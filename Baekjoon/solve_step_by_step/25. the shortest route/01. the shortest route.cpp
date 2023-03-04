/**
 * @file 01. the shortest route.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 가중치가 우선적으로 오름차순의 기준이 되어야 한다.
 * @date 2021-10-24 23:13:41
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int vertex, edge;                            // 정점의 개수, 간선의 개수
int start;                                   // 시작 정점
int u, v, w;                                 // 출발지, 도착지, 가중치
vector<vector<pair<int, int>>> graph(20001); // graph[idx] : idx에서 갈 수 있는 정점과 가중치가 저장된 벡터
int dp[20001];                               // dp[idx] : start -> idx까지 가는데 필요한 가중치의 최솟값

void dijkstra()
{
    fill(dp, dp + 20001, 200001); // dp를 나올 수 있는 최대 가중치로 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_q;
    min_q.push(make_pair(0, start)); // 초기값 삽입
    dp[start] = 0;                   // 출발 지점으로 가는 것은 0

    int now, next, weight, next_weight;
    while (!min_q.empty())
    {
        now = min_q.top().second;   // 현재 위치
        weight = min_q.top().first; // 현재 가중치
        min_q.pop();

        if (dp[now] < weight) // 현재 가중치가 지금까지 구한 가중치보다 크면 계산이 필요없다
            continue;

        for (int i = 0; i < graph[now].size(); i++)
        {
            next = graph[now][i].second;                // 다음으로 갈 수 있는 위치
            next_weight = weight + graph[now][i].first; // next로 갔을 때 필요한 가중치

            if (next_weight < dp[next]) // 구했던 것보다 더 작으면 최신화
            {
                dp[next] = next_weight;
                min_q.push({next_weight, next}); // 정점 탐색
            }
        }
    }
}

int main()
{
    cin >> vertex >> edge;
    cin >> start;

    for (int i = 0; i < edge; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }

    dijkstra();

    for (int i = 1; i <= vertex; i++)
    {
        if (dp[i] == 200001) // 초기값 그대로라면 갈 수 없는 곳
            cout << "INF" << '\n';
        else
            cout << dp[i] << '\n';
    }
    return 0;
}