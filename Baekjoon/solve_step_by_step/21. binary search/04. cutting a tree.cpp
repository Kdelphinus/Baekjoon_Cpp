/**
 * @file 04. cutting a tree.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-24 22:51:51
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long height;
vector<long long> trees;

void cutting(long long start, long long end, long long need_tree)
{
    if (start > end)
        return;

    long long mid = (start + end) / 2;
    long long total = 0;
    for (int i = 0; i < trees.size(); i++)
    {
        if (mid < trees[i]) // ���ܱ��� ���̺��� ������ Ŀ�� ������ �ڸ� �� �ִ�
            total += (trees[i] - mid);
    }

    if (total >= need_tree) // �ڸ� ������ ���ϴ� �������� ���ų� ���� ��
    {
        if (height < mid)                        // ���ߴ� ���̺��� �� ���� ���̶��
            height = mid;                        // ���� �ֽ�ȭ
        return cutting(mid + 1, end, need_tree); // ���ܱ� ���̸� �� ������ Ȯ��
    }
    else                                           // �ڸ� ������ ������ ��
        return cutting(start, mid - 1, need_tree); // ���ܱ� ���̸� �� ���缭 Ȯ��
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num;
    long long tmp, need_tree;
    cin >> num >> need_tree;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        trees.push_back(tmp);
    }
    sort(trees.begin(), trees.end());
    cutting(0, trees[num - 1], need_tree);
    cout << height;

    return 0;
}