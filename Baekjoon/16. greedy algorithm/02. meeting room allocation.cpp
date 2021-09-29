/**
 * @file 02. meeting room allocation.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-09 20:14:17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int allocation(int num)
{
    vector<vector<int>> meeting(num, vector<int>(2, 0));
    for (int i = 0; i < num; i++)
        cin >> meeting[i][0] >> meeting[i][1];

    sort(meeting.begin(), meeting.end());

    int cnt = 1;
    int end = meeting[0][1];
    for (int i = 1; i < num; i++)
    {
        if (meeting[i][0] >= end) // 현재 회의가 끝난 후, 다음 회의가 열리면 다음 회의를 배정한다
        {
            end = meeting[i][1];
            cnt++;
        }
        else if (meeting[i][1] < end) // 현재 회의보다 다음 회의가 먼저 끝나면 현재 회의를 빼고 다음 회의를 배정한다
            end = meeting[i][1];
    }

    return cnt;
}

int main()
{
    int num;
    cin >> num;
    cout << allocation(num);
    return 0;
}