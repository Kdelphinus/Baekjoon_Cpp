/**
 * @file 02. N and M (2).cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-31 00:25:08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int check[9];

void combination(int n, int m)
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
        if (arr.size() == 0 && check[i] == 0)
        {
            arr.push_back(i);
            check[i] = 1;
            combination(n, m);
            arr.pop_back();
            check[i] = 0;
        }
        else if (arr.back() < i && check[i] == 0) // 이미 들어간 수보다 큰 수만 들어갈 수 있다(중복방지)
        {
            arr.push_back(i);
            check[i] = 1;
            combination(n, m);
            arr.pop_back();
            check[i] = 0;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    combination(n, m);
    return 0;
}