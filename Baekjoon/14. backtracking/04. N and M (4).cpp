/**
 * @file 04. N and M (4).cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-31 00:32:01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void combinations_with_replacement(int n, int m)
{
    if (arr.size() == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (arr.size() == 0)
        {
            arr.push_back(i);
            combinations_with_replacement(n, m);
            arr.pop_back();
        }
        else if (arr.back() <= i)
        {
            arr.push_back(i);
            combinations_with_replacement(n, m);
            arr.pop_back();
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    combinations_with_replacement(n, m);
    return 0;
}