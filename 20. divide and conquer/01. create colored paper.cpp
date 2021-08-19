/**
 * @file 01. create colored paper.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-19 22:40:26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

int white, blue;
vector<vector<int>> paper;

void dc(int num, int x, int y)
{
    int flag = 0, standard = paper[y][x];

    if (num == 1) // 종이의 크기가 1이면 색종이 바로 완성
    {
        if (standard)
            blue++;
        else
            white++;
        return;
    }

    for (int i = y; i < y + num; i++) // 기준 칸과 다른 칸을 비교한다
    {
        if (flag)
            break;
        for (int j = x; j < x + num; j++)
        {
            if (standard != paper[i][j]) // 만약 기준 칸과 다른 칸의 색이 다르면
            {
                flag = 1; // 표시 후 종료
                break;
            }
        }
    }

    if (flag) // 다른 색이 있었으면
    {
        num /= 2;                  // 크기를 절반으로 나누고
        dc(num, x, y);             // 좌측상단 확인
        dc(num, x, y + num);       // 좌측하단 확인
        dc(num, x + num, y);       // 우측상단 확인
        dc(num, x + num, y + num); // 우측하단 확인
    }
    else // 다른 색이 없으면 색종이 추가
    {
        if (standard)
            blue++;
        else
            white++;
    }
}

int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        vector<int> tmp(num, 0);
        for (int j = 0; j < num; j++)
            cin >> tmp[j];
        paper.push_back(tmp);
    }
    dc(num, 0, 0);
    cout << white << '\n'
         << blue;
    return 0;
}