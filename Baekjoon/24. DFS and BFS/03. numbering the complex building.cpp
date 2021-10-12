/**
 * @file 03. numbering the complex building.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-12 23:58:01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num, building_num;
vector<vector<int>> visit(26, vector<int>(26, 0));
vector<vector<char>> map(26, vector<char>(26));

void DFS(int i, int j)
{
    visit[i][j] = 1;
    building_num++;

    if (i - 1 >= 0 && visit[i - 1][j] == 0 && map[i - 1][j] == '1')
        DFS(i - 1, j);
    if (j - 1 >= 0 && visit[i][j - 1] == 0 && map[i][j - 1] == '1')
        DFS(i, j - 1);
    if (i + 1 < num && visit[i + 1][j] == 0 && map[i + 1][j] == '1')
        DFS(i + 1, j);
    if (j + 1 < num && visit[i][j + 1] == 0 && map[i][j + 1] == '1')
        DFS(i, j + 1);
}

int main()
{
    string tmp;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        for (int j = 0; j < num; j++)
            map[i][j] = tmp[j];
    }

    vector<int> complex;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (map[i][j] == '1' && visit[i][j] == 0)
            {
                DFS(i, j);
                complex.push_back(building_num);
                building_num = 0;
            }
        }
    }

    sort(complex.begin(), complex.end());
    cout << complex.size() << '\n';
    for (int i = 0; i < complex.size(); i++)
        cout << complex[i] << '\n';

    return 0;
}