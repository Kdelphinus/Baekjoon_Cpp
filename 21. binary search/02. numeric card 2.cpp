/**
 * @file 02. numeric card 2.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-23 23:06:48
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;
vector<int> standard;

void bs(int tmp, int start, int end)
{
    if (start > end) // ���������� ���������� ũ�� ã�� �� ����
        return;

    int mid = (start + end) / 2;

    if (standard[mid] > tmp) // �߰������� �۴ٸ� ������ ���ʸ� Ȯ��
        bs(tmp, start, mid - 1);
    else if (standard[mid] < tmp) // �߰������� ũ�ٸ� ������ �����ʸ� Ȯ��
        bs(tmp, mid + 1, end);
    else // �߰����� ���ٸ� ������ �߰��ϰ� �����ʰ� ���� ��� Ȯ��
    {
        cnt++;
        bs(tmp, start, mid - 1), bs(tmp, mid + 1, end);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        standard.push_back(tmp);
    }

    sort(standard.begin(), standard.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        bs(tmp, 0, n - 1);
        cout << cnt << " ";
        cnt = 0;
    }
    return 0;
}