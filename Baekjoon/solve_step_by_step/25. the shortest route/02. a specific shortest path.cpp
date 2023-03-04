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

int vertex, edge; // ������ ����, ������ ����
int a, b, c;      // ���� 1, ���� 2, �� ���� ���� �Ÿ�
int way1, way2;   // ���ľ� �� ���� 1, ���ľ� �� ���� 2
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
    dp_one = dijkstra(1);     // 1�� �������� ������� ��, �ִܰŸ��� ������ �迭
    dp_way1 = dijkstra(way1); // way1�� �������� ������� ��, �ִܰŸ��� ������ �迭
    dp_way2 = dijkstra(way2); // way2�� �������� ������� ��, �ִܰŸ��� ������ �迭

    long long result = min(dp_one[way1] + dp_way1[way2] + dp_way2[vertex], dp_one[way2] + dp_way2[way1] + dp_way1[vertex]);
    if (result < INT_MAX) // ���� �ʱⰪ���� �۾ƾ� �� �� �ִ� ��
        cout << result;
    else
        cout << -1;

    return 0;
}