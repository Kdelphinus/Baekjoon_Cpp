/**
 * @file 02. exciting function execution.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-03 23:34:16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

int w_arr[21][21][21];

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    if (w_arr[a][b][c])
        return w_arr[a][b][c];

    if (a < b && b < c)
    {
        w_arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return w_arr[a][b][c];
    }

    w_arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return w_arr[a][b][c];
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    while (1)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
    return 0;
}