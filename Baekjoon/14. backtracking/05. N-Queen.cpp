/**
 * @file 05. N-Queen.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-03 15:20:39
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

int cnt, num;
int left_cross[30], right_cross[30], height[15];

void queen(int i) // i는 가로축을 의미
{
    if (i == num) // 모든 줄마다 퀸을 하나씩 놨다면 성공
    {
        cnt++;
        return;
    }

    for (int j = 0; j < num; j++) // 가로는 i축으로 고정, 세로축을 하나씩 살펴보며 놓을 수 있는 곳을 찾음
    {
        if (height[j] == 0 && left_cross[i - j + num - 1] == 0 && right_cross[i + j] == 0) // 세로, 좌우 대각선에 모두 퀸이 없다면(가로는 함수가 i를 사용해 이미 겹치지 않음)
        {
            // 세로, 좌우 대각선에 퀸이 오면 안됨을 표시
            height[j] = 1;
            left_cross[i - j + num - 1] = 1;
            right_cross[i + j] = 1;

            // 다음 가로줄로 이동
            queen(i + 1);

            // 다 확인했으면 다시 퀸을 뺌
            height[j] = 0;
            left_cross[i - j + num - 1] = 0;
            right_cross[i + j] = 0;
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> num;
    queen(0);
    cout << cnt;

    return 0;
}