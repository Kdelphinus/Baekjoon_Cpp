/**
 * @file pick two and add them.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief Monthly Code Challenge
 * @date 2021-11-08 21:26:41
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
            answer.push_back(numbers[i] + numbers[j]);
    }

    sort(answer.begin(), answer.end());                               // 정렬
    answer.erase(unique(answer.begin(), answer.end()), answer.end()); // 중복 제거

    return answer;
}