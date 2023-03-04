/**
 * @file 06. ring.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-13 22:42:48
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) // 최대공약수를 구하는 함수
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void ring(int num)
{
    vector<int> arr(num, 0);
    for (int i = 0; i < num; i++)
        cin >> arr[i];

    int tmp, standard = arr[0]; // 기준이 되는 링
    for (int i = 1; i < num; i++)
    {
        tmp = gcd(arr[i], standard);                           // 두 링의 최대공약수를 구하여
        cout << standard / tmp << "/" << arr[i] / tmp << "\n"; // 나누면 된다
    }
}

int main()
{
    int num;
    cin >> num;
    ring(num);
    return 0;
}