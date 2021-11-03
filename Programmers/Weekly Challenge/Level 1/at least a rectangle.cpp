/**
 * @file at least a rectangle.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief Weekly Challenge
 * @date 2021-11-03 19:02:48
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int width = 0, height = 0;
    int tmp_w = 0, tmp_h = 0;
    for (int i = 0; i < sizes.size(); i++)
    {
        tmp_w = sizes[i][0];
        tmp_h = sizes[i][1];
        if (sizes[i][0] > sizes[i][1])
        {
            tmp_w = sizes[i][1];
            tmp_h = sizes[i][0];
        }

        width = max(width, tmp_w);
        height = max(height, tmp_h);
    }

    return width * height;
}