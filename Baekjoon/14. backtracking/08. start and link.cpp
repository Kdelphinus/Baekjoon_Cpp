/**
 * @file 08. start and link.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-03 17:06:17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num, min_diff = 1000000000;
int check[9];
vector<int> start;
vector<vector<int>> football_stat(20, vector<int>(20, 0));

void combination(int n, int m)
{
    if (start.size() == m) // start���� �ϼ��ƴٸ�
    {
        int start_stat = 0, link_stat = 0; // �� ���� ������ ������ ����
        vector<int> link;                  // link��
        for (int i = 0; i < n; i++)
        {
            if (find(start.begin(), start.end(), i) == start.end()) // start���� ���� ���� �������� link���� ����
                link.push_back(i);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++) // �� ���� ������ ���� ����
            {
                start_stat += football_stat[start[i]][start[j]];
                link_stat += football_stat[link[i]][link[j]];
            }
        }

        int diff;
        diff = abs(start_stat - link_stat); // �� ���� �������̸� �������� ����
        if (min_diff > diff)                // �ּ� ���̺��� �� �۴ٸ�
            min_diff = diff;                // �ּ� ���̸� �ֽ�ȭ

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (start.size() == 0 && check[i] == 0) // ó�� �ִ� ������
        {
            start.push_back(i); // ������ start���� �ְ�
            check[i] = 1;       // ������ ���� ������ ǥ��
            combination(n, m);  // ���� ������ ������ �̵�
            start.pop_back();   // ���� �� ®�ٸ� �ٽ� ������ ��
            check[i] = 0;       // ���� ������ ǥ��
        }
        else if (start.back() < i && check[i] == 0) // �̹� �� ������ ū ���� �� �� �ִ�(�ߺ�����, ������ ���ʴ�� 0���� ��ȣ�� �־���)
        {
            start.push_back(i); // ������ start���� �ְ�
            check[i] = 1;       // ������ ���� ������ ǥ��
            combination(n, m);  // ���� ������ ������ �̵�
            start.pop_back();   // ���� �� ®�ٸ� ������ ��
            check[i] = 0;       // ���� ������ ǥ��
        }
    }
}

int main()
{
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            int tmp;
            cin >> tmp;
            football_stat[i][j] = tmp;
        }
    }

    combination(num, num / 2); // 2������ �����Ƿ� ���ݾ� ����
    cout << min_diff;

    return 0;
}