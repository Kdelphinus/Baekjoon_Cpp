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
        if (mid < trees[i]) // 절단기의 높이보다 나무가 커야 나무를 자를 수 있다
            total += (trees[i] - mid);
    }

    if (total >= need_tree) // 자른 나무가 원하는 나무보다 같거나 많을 때
    {
        if (height < mid)                        // 구했던 높이보다 더 높은 높이라면
            height = mid;                        // 높이 최신화
        return cutting(mid + 1, end, need_tree); // 절단기 높이를 더 높여서 확인
    }
    else                                           // 자른 나무가 부족할 때
        return cutting(start, mid - 1, need_tree); // 절단기 높이를 더 낮춰서 확인
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