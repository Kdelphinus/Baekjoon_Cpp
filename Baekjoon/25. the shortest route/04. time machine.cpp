#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int city, route;
int start, arrival, time;
int dp[501];
vector<vector<pair<int, int>>> graph(501);

bool bellman(int start)
{
    fill(dp, dp + 501, INT_MAX);
    dp[start] = 0;

    for (int i = 1; i < city; i++)
    {
        for (int wayp = 1; wayp <= city; wayp++)
        {
            for (int j = 0; j < graph[wayp].size(); j++)
            {
                arrival = graph[wayp][j].second;
                time = graph[wayp][j].first;

                if (dp[arrival] > dp[wayp] + time)
                    dp[arrival] = dp[wayp] + time;
            }
        }
    }

    for (int wayp = 1; wayp <= city; wayp++)
    {
        for (int j = 0; j < graph[wayp].size(); j++)
        {
            arrival = graph[wayp][j].second;
            time = graph[wayp][j].first;

            if (dp[arrival] > dp[wayp] + time)
                return false;
        }
    }
    return true;
}

int main()
{
    cin >> city >> route;
    for (int i = 0; i < route; i++)
    {
        cin >> start >> arrival >> time;
        graph[start].push_back({time, arrival});
    }

    if (bellman(1))
    {
        for (int i = 2; i <= city; i++)
        {
            if (dp[i] < INT_MAX)
                cout << dp[i] << '\n';
            else
                cout << -1 << '\n';
        }
    }
    else
        cout << -1;

    return 0;
}