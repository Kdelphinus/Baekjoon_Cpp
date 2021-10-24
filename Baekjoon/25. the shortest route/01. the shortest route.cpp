/**
 * @file 01. the shortest route.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief ����ġ�� �켱������ ���������� ������ �Ǿ�� �Ѵ�.
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

int vertex, edge;                            // ������ ����, ������ ����
int start;                                   // ���� ����
int u, v, w;                                 // �����, ������, ����ġ
vector<vector<pair<int, int>>> graph(20001); // graph[idx] : idx���� �� �� �ִ� ������ ����ġ�� ����� ����
int dp[20001];                               // dp[idx] : start -> idx���� ���µ� �ʿ��� ����ġ�� �ּڰ�

void dijkstra()
{
    fill(dp, dp + 20001, 200001); // dp�� ���� �� �ִ� �ִ� ����ġ�� �ʱ�ȭ
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_q;
    min_q.push(make_pair(0, start)); // �ʱⰪ ����
    dp[start] = 0;                   // ��� �������� ���� ���� 0

    int now, next, weight, next_weight;
    while (!min_q.empty())
    {
        now = min_q.top().second;   // ���� ��ġ
        weight = min_q.top().first; // ���� ����ġ
        min_q.pop();

        if (dp[now] < weight) // ���� ����ġ�� ���ݱ��� ���� ����ġ���� ũ�� ����� �ʿ����
            continue;

        for (int i = 0; i < graph[now].size(); i++)
        {
            next = graph[now][i].second;                // �������� �� �� �ִ� ��ġ
            next_weight = weight + graph[now][i].first; // next�� ���� �� �ʿ��� ����ġ

            if (next_weight < dp[next]) // ���ߴ� �ͺ��� �� ������ �ֽ�ȭ
            {
                dp[next] = next_weight;
                min_q.push({next_weight, next}); // ���� Ž��
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
        if (dp[i] == 200001) // �ʱⰪ �״�ζ�� �� �� ���� ��
            cout << "INF" << '\n';
        else
            cout << dp[i] << '\n';
    }
    return 0;
}