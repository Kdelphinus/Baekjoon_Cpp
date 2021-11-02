/**
 * @file dart game.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 2018 KAKAO BLIND RECRUITMENT
 * @date 2021-11-02 20:27:33
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(string dartResult)
{
    int idx = 0;
    vector<int> score;

    while (idx < dartResult.size())
    {
        if (isdigit(dartResult[idx]))
        {
            if (idx + 1 < dartResult.size() && isdigit(dartResult[idx + 1]))
            {
                score.push_back(10);
                idx += 2;
            }
            else
            {
                score.push_back(dartResult[idx] - '0');
                idx++;
            }
        }
        else
        {
            if (dartResult[idx] == 'D')
                score[score.size() - 1] = score[score.size() - 1] * score[score.size() - 1];
            else if (dartResult[idx] == 'T')
                score[score.size() - 1] = score[score.size() - 1] * score[score.size() - 1] * score[score.size() - 1];
            else if (dartResult[idx] == '*')
            {
                score[score.size() - 1] *= 2;
                score[score.size() - 2] *= 2;
            }
            else if (dartResult[idx] == '#')
                score[score.size() - 1] *= -1;
            idx++;
        }
    }

    return accumulate(score.begin(), score.end(), 0);
}