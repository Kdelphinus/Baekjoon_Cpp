/**
 * @file 03. downhill road.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-10 19:15:43
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

int width, height;
vector<vector<int>> dp;
vector<vector<int>> roads;

int downhill(int y, int x)
{ // roads[y][x]���� ������������ ���� ����� ���� ���ϴ� �Լ�
    // 0, 0���� �����ϸ� ������������ �� �������� �Ž��� �ö���� ���
    // �׷��⿡ dp�� �ʱⰪ�� ���������� 1�� �����ϰ� ����� ��������� dp�� ����
    if (dp[y][x] != -1)
        return dp[y][x];

    int tmp = 0;
    if (x + 1 < width && roads[y][x] > roads[y][x + 1])
        tmp += downhill(y, x + 1);
    if (x - 1 >= 0 && roads[y][x] > roads[y][x - 1])
        tmp += downhill(y, x - 1);
    if (y + 1 < height && roads[y][x] > roads[y + 1][x])
        tmp += downhill(y + 1, x);
    if (y - 1 >= 0 && roads[y][x] > roads[y - 1][x])
        tmp += downhill(y - 1, x);

    dp[y][x] = tmp;
    return dp[y][x];
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int tmp;
    cin >> height >> width;

    for (int i = 0; i < height; i++)
    {
        vector<int> tmp_vec;
        for (int j = 0; j < width; j++)
        {
            cin >> tmp;
            tmp_vec.push_back(tmp);
        }
        vector<int> minus_one(width, -1);
        roads.push_back(tmp_vec);
        dp.push_back(minus_one);
    }

    dp[height - 1][width - 1] = 1; // ��������
    cout << downhill(0, 0);

    // dp Ȯ�ο�
    //cout << '\n';
    //for (int i = 0; i < height; i++)
    //{
    //    for (int j = 0; j < width; j++)
    //        cout << dp[i][j] << ' ';
    //    cout << '\n';
    //}

    return 0;
}