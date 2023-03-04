/**
 * @file 11. number of factorial 0.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-16 20:19:25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

// 팩토리얼은 수를 차례대로 곱하는 것이다.
// 10의 배수가 있을 때마다 0이 하나씩 붙을 것이고 10은 2와 5의 곱으로 만들 수 있다
// 5의 배수보다 2의 배수가 압도적으로 많기에 5의 배수의 갯수만 구하면 뒤에 붙은 0의 개수를 구할 수 있다
int fact_zero(int num)
{
    int cnt = num / 5 + num / 25 + num / 125;
    return cnt;
}

int main()
{
    int num;
    cin >> num;
    cout << fact_zero(num);
    return 0;
}