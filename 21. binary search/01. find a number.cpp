/**
 * @file 01. find a number.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-23 22:50:17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> standard; // ���͸� �Լ��� ������ �ð� �ʰ��� ���� �߻��Ѵ�

int bs(int tmp)
{
    int start = 0;
    int end = standard.size() - 1;

    while (start < end) // ������ ���������� ���������� �۾ƾ��Ѵ�
    {
        int mid = (start + end) / 2;

        // �� �κ� �� �ϳ��� ��ġ�� ���� ������ ���� �ִ� �������� 1����
        if (standard[start] == tmp)
            return 1;
        if (standard[mid] == tmp)
            return 1;
        if (standard[end] == tmp)
            return 1;

        if (standard[mid] < tmp) // �߰����� ũ�� ������ �����ʸ� Ȯ���ϸ� �ȴ�
            start = mid + 1;
        else // �߰����� ������ ������ ���ʸ� Ȯ���ϸ� �ȴ�
            end = mid - 1;
    }

    return 0; // ���������� ���������� Ŀ���� ���� ����
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

    sort(standard.begin(), standard.end()); // ������ �Ǵ� ���� ����

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        cout << bs(tmp) << '\n';
    }

    return 0;
}