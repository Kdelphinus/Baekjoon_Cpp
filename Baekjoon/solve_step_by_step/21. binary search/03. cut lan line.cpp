/**
 * @file 03. cut lan line.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-24 22:04:54
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int len = 1;
vector<long long> lines;

void cut(long long start, long long end, int n)
{
    if (start > end)
        return;

    long long cnt = 0;
    long long mid = (start + end) / 2;

    for (int i = 0; i < lines.size(); i++) // ���� �������� ���� �� �ִ� mid ������ ���� ��
        cnt += lines[i] / mid;

    if (cnt >= n) // ���� �� �ִ� ������ ���� ����ġ�� ������ ��
    {
        if (mid > len)               // �������� �� �� �������� ���� �� �ִٸ�
            len = mid;               // ���� �� �ִ� ������ ���̸� �ֽ�ȭ�ϰ�
        return cut(mid + 1, end, n); // �� �� ���� ���̸� ���� �� �ִ��� Ȯ��
    }
    else                               // ������ �������� ���ϸ�
        return cut(start, mid - 1, n); // �� ª�� ���� ���̸� Ȯ��
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int k, n;
    long long tmp;
    cin >> k >> n; // ������ �ִ� ������ ����, �ʿ��� ������ ����
    for (int i = 0; i < k; i++)
    {
        cin >> tmp;
        lines.push_back(tmp);
    }

    sort(lines.begin(), lines.end());

    cut(2, lines[k - 1], n);
    cout << len;

    return 0;
}