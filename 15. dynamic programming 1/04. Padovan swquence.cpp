/**
 * @file 04. Padovan swquence.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-04 18:38:19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr(101, 0);

long long padovan(int num)
{
    if (arr[num])
        return arr[num];

    for (int i = 3; i <= num; i++)
        arr[i] = arr[i - 2] + arr[i - 3];

    return arr[num];
}

int main()
{
    int test;
    cin >> test;

    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;

    for (int i = 0; i < test; i++)
    {
        int num;
        cin >> num;
        cout << padovan(num) << '\n';
    }
    return 0;
}