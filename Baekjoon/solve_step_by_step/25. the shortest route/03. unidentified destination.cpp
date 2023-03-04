/**
 * @file 03. unidentified destination.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-25 01:25:26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int cross, roads, target;
int start, way1, way2;
int a, b, d;
int reserve;
int INT_MAX = 2147483647;
vector<vector<pair<int, int>>> graph(2001);

long long *dijkstra(vector<vector<pair<int, int>>> graph, int start_cross)
{
    long long *dp = (long long *)malloc(sizeof(long long) * (cross + 1));
    fill(dp, dp + cross + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start_cross});
    dp[start_cross] = 0;

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
    int test;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        cin >> cross >> roads >> target;
        cin >> start >> way1 >> way2;
        vector<vector<pair<int, int>>> graph(cross + 1);

        for (int j = 0; j < roads; j++)
        {
            cin >> a >> b >> d;
            graph[a].push_back({d, b});
            graph[b].push_back({d, a});
        }

        long long *start_dp, *way1_dp, *way2_dp;
        start_dp = dijkstra(graph, start);
        way1_dp = dijkstra(graph, way1);
        way2_dp = dijkstra(graph, way2);

        // 목적지로 바로가는 최단 거리와 예술가가 지가간 거리를 거쳐 가는 거리가 같아야 목적지 후보이다
        vector<int> target_list;
        for (int j = 0; j < target; j++)
        {
            cin >> reserve;
            if (start_dp[way1] + way1_dp[way2] + way2_dp[reserve] == start_dp[reserve])
                target_list.push_back(reserve);
            else if (start_dp[way2] + way2_dp[way1] + way1_dp[reserve] == start_dp[reserve])
                target_list.push_back(reserve);
        }

        sort(target_list.begin(), target_list.end());
        for (int j = 0; j < target_list.size(); j++)
            cout << target_list[j] << ' ';
        cout << '\n';
    }
    return 0;
}