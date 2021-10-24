/**
 * @file 02. a specific shortest path.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-25 00:21:43
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int vertex, edge; // 정점의 개수, 간선의 개수
int a, b, c;      // 정점 1, 정점 2, 두 정점 간의 거리
int way1, way2;   // 거쳐야 할 정점 1, 거쳐야 할 정점 2
vector<vector<pair<int, int>>> graph(801);

long long *dijkstra(int start)
{
    long long *dp = (long long *)malloc(sizeof(long long) * 801);
    fill(dp, dp + 801, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});
    dp[start] = 0;

    int now, next, weight, next_weight;
    while (!q.empty())
    {
        weight = q.top().first;
        now = q.top().second;
        q.pop();

        if (dp[now] < weight)
            continue;

        for (int i = 0; i < graph[now].size(); i++)
        {
            next = graph[now][i].second;
            next_weight = weight + graph[now][i].first;

            if (dp[next] > next_weight)
            {
                dp[next] = next_weight;
                q.push({next_weight, next});
            }
        }
    }

    return dp;
}

int main()
{
    cin >> vertex >> edge;
    for (int i = 0; i < edge; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    cin >> way1 >> way2;

    long long *dp_one, *dp_way1, *dp_way2;
    dp_one = dijkstra(1);     // 1번 정점에서 출발했을 때, 최단거리를 저장한 배열
    dp_way1 = dijkstra(way1); // way1번 정점에서 출발했을 때, 최단거리를 저장한 배열
    dp_way2 = dijkstra(way2); // way2번 정점에서 출발했을 때, 최단거리를 저장한 배열

    long long result = min(dp_one[way1] + dp_way1[way2] + dp_way2[vertex], dp_one[way2] + dp_way2[way1] + dp_way1[vertex]);
    if (result < INT_MAX) // 합이 초기값보다 작아야 갈 수 있는 곳
        cout << result;
    else
        cout << -1;

    return 0;
}