/**
 * @file 11. bipartite graph.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief �̺� �׷����� ����: https://gmlwjd9405.github.io/2018/08/23/algorithm-bipartite-graph.html
 * @date 2021-10-19 22:08:44
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> linked(20001); // ����� ������ ������ ����
int nodes[20001];                  // ������ ���� ������ �迭

bool BFS(int start)
{
    int tmp;
    nodes[start] = 1; // ���� ĥ���ش�
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        tmp = q.front();
        q.pop();

        for (int i = 0; i < linked[tmp].size(); i++)
        {                                   // ����� ������ �ϳ��� Ȯ��
            if (nodes[linked[tmp][i]] == 0) // ���� ���� ����� ��
            {
                nodes[linked[tmp][i]] = -nodes[tmp]; // ���� ���� �ٸ� ���� ĥ�ϰ�
                q.push(linked[tmp][i]);              // Ž�� ������ �߰�
            }
            else // ���� �ִ� ����� ��
            {
                if (nodes[linked[tmp][i]] == nodes[tmp]) // ���� ���̸�
                    return false;                        // �̺� �׷����� �ƴϴ�
            }
        }
    }
    return true; // ��� Ž���� �����ٸ� �̺� �׷����̴�
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
        for (int j = 0; j < linked_num; j++) // ����� ���� ����
        {
            cin >> start >> end;
            linked[start].push_back(end);
            linked[end].push_back(start);
        }

        for (int n = 1; n <= node_num; n++)
        {
            if (nodes[n] == 0) // ���� ���� ����� ��
            {
                if (!BFS(n)) // ������ ���� ���� ��ġ��
                {
                    isTrue = "NO"; // �̺� �׷����� �ƴϴ�
                    break;
                }
            }
        }
        cout << isTrue << '\n';
        for (int j = 1; j <= node_num; j++)
        {
            nodes[j] = 0;      // ����� �� �ʱ�ȭ
            linked[j].clear(); // ����� ���� �ʱ�ȭ
        }
    }

    return 0;
}