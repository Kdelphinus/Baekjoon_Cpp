/**
 * @file 02. virus.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-11 19:05:44
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int dfs_cnt, bfs_cnt;
int computer_num, linked_num;
vector<int> visited(101);
vector<vector<int>> linked(101, vector<int>(101));

void DFS(int node)
{
    dfs_cnt++;
    visited[node] = 1;

    for (int i = 1; i <= computer_num; i++)
    {
        if (visited[i] == 0 && linked[node][i] == 1)
            DFS(i);
    }
}

void BFS(int node)
{
    deque<int> queue;
    queue.push_back(node);

    while (!queue.empty())
    {
        node = queue.front();
        queue.pop_front();
        visited[node] = 1;
        bfs_cnt++;

        for (int i = 1; i <= computer_num; i++)
        {
            if (visited[i] == 0 && linked[node][i] == 1)
            {
                queue.push_back(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int tmp1, tmp2;

    cin >> computer_num >> linked_num;
    for (int i = 0; i < linked_num; i++)
    {
        cin >> tmp1 >> tmp2;
        linked[tmp1][tmp2] = 1;
        linked[tmp2][tmp1] = 1;
    }

    // 시작하는 컴퓨터는 빼준다
    DFS(1);
    cout << dfs_cnt - 1;

    //BFS(1);
    //cout << bfs_cnt - 1;

    return 0;
}