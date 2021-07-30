/**
 * @file 03. N and M (3).cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-31 00:28:24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void product(int n, int m)
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
        arr.push_back(i);
        product(n, m);
        arr.pop_back();
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    product(n, m);
    return 0;
}