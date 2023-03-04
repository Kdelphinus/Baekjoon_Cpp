/**
 * @file 01. DFS and BFS.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-11 18:54:47
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int node_num, linked_num;
vector<vector<int>> graph(1001, vector<int>(1001));
vector<int> visited(1001);

void DFS(int node)
{
    cout << node << ' ';
    visited[node] = 1;
    for (int i = 1; i <= node_num; i++)
    {
        if (visited[i] == 0 && graph[node][i] == 1)
            DFS(i);
    }
}

void BFS(int node)
{
    deque<int> queue;
    queue.push_back(node);
    visited[node] = 0;

    while (!queue.empty())
    {
        node = queue.front();
        cout << node << ' ';
        queue.pop_front();

        for (int i = 1; i <= node_num; i++)
        {
            if (visited[i] == 1 && graph[node][i] == 1)
            {
                queue.push_back(i);
                visited[i] = 0;
            }
        }
    }
}

int main()
{
    int start, tmp1, tmp2;
    cin >> node_num >> linked_num >> start;

    for (int i = 0; i < linked_num; i++)
    {
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = 1;
        graph[tmp2][tmp1] = 1;
    }

    DFS(start);
    cout << '\n';
    BFS(start);

    return 0;
}