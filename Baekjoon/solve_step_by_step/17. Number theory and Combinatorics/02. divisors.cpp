/**
 * @file 02. divisors.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-10 21:38:08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int divisors(int num)
{
    vector<int> divi(num, 0);
    for (int i = 0; i < num; i++)
        cin >> divi[i];

    // ����� �ּڰ��� �ִ��� ���ϸ� N�� ���´�
    return *max_element(divi.begin(), divi.end()) * *min_element(divi.begin(), divi.end());
}

int main()
{
    int num;
    cin >> num;
    cout << divisors(num);
    return 0;
}