/**
 * @file 02. quad tree.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-19 23:03:03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> video;

void compression(int num, int x, int y)
{
    if (num == 1) // 비디오 크기가 1이면 압축 바로 완료
    {
        cout << video[y][x];
        return;
    }

    int flag = 0;
    for (int i = y; i < y + num; i++) // 기준점과 다른 것이 있으면 바로 종료
    {
        if (flag)
            break;
        for (int j = x; j < x + num; j++)
        {
            if (video[y][x] != video[i][j])
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag) // 다른 것이 있었다면
    {
        cout << "(";                        // 분할 시작
        num /= 2;                           // 크기를 두개로 나누고
        compression(num, x, y);             // 좌측 상단
        compression(num, x + num, y);       // 우측 상단
        compression(num, x, y + num);       // 좌측 하단
        compression(num, x + num, y + num); // 우측 하단
        cout << ")";                        // 분할 종료
    }
    else                     // 다른 것이 없다면
        cout << video[y][x]; // 기준점으로 압축
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num;
    cin >> num;
    for (int i = 0; i < num; i++) // 붙어있는 숫자는 한 번에 받아버리기에 문자열로 받아 따로 저장
    {
        string tmp;
        vector<int> tmp_vec(num, 0);
        cin >> tmp;
        for (int j = 0; j < num; j++)
            tmp_vec[j] = tmp[j] - '0';
        video.push_back(tmp_vec);
    }
    compression(num, 0, 0);
    return 0;
}