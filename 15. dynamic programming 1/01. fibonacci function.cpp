/**
 * @file 01. fibonacci function.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-03 23:11:52
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> zero_one(41, vector<int>(2, 0)); // 숫자 최대 크기가 40

void fib()
{
    zero_one[0][0] = 1;
    zero_one[1][1] = 1;

    for (int i = 2; i < 41; i++)
    {
        zero_one[i][0] = zero_one[i - 1][0] + zero_one[i - 2][0];
        zero_one[i][1] = zero_one[i - 1][1] + zero_one[i - 2][1];
    }
}

int main()
{
    int test;
    cin >> test;

    fib();
    for (int i = 0; i < test; i++)
    {
        int num;
        cin >> num;
        cout << zero_one[num][0] << " " << zero_one[num][1] << "\n";
    }
    return 0;
}