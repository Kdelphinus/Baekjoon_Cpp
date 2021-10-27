/**
 * @file n numbers spaced by x.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-28 01:35:40
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n)
{
    int tmp = x;
    vector<long long> answer;
    for (int i = 0; i < n; i++)
    {
        answer.push_back(tmp);
        tmp += x;
    }
    return answer;
}