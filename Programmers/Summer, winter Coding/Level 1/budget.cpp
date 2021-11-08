/**
 * @file budget.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief Summer/Winter Coding(~2018)
 * @date 2021-11-08 21:32:19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer = 0, idx = 0;
    sort(d.begin(), d.end());

    while (budget > 0 && idx < d.size())
    {
        if (d[idx] > budget)
            break;

        budget -= d[idx++];
        answer++;
    }

    return answer;
}