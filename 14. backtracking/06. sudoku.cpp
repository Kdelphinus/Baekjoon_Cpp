/**
 * @file 06. sudoku.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-03 16:02:13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board(9, vector<int>(9, 0));
vector<pair<int, int>> zeros;
int flag;

void sudoku(int n)
{
    if (n == zeros.size()) // 모든 빈 칸을 확인했다면
    {
        flag = 1;                   // 답안을 다 채웠다고 표시하고
        for (int y = 0; y < 9; y++) // 답안 출력
        {
            for (int x = 0; x < 9; x++)
                cout << board[y][x] << " ";
            cout << "\n";
        }
        return;
    }

    if (flag) // 이미 답안이 출력되었다면 바로 리턴
        return;

    int x, y;
    int possible[10] = {0}; // 빈 칸에 들어갈 수 있는 숫자를 저장할 배열
    x = zeros[n].first;     // 빈 칸의 x좌표
    y = zeros[n].second;    // 빈 칸의 y좌표

    for (int j = 0; j < 9; j++)
    {
        if (possible[board[y][j]] == 0) // 가로 줄 확인
            possible[board[y][j]]++;
        if (possible[board[j][x]] == 0) // 세로 줄 확인
            possible[board[j][x]]++;
    }

    for (int j = y / 3 * 3; j < y / 3 * 3 + 3; j++) // 3 * 3칸 안에 있는 숫자 확인
    {
        for (int k = x / 3 * 3; k < x / 3 * 3 + 3; k++)
        {
            if (possible[board[j][k]] == 0)
                possible[board[j][k]]++;
        }
    }

    for (int j = 1; j <= 9; j++)
    {
        if (possible[j] == 0) // 가능한 숫자면
        {
            board[y][x] = j; // 숫자를 바꾸고
            sudoku(n + 1);   // 다음 빈 칸으로 이동
            board[y][x] = 0; // 만약 넣은 숫자가 틀리다면 다시 빈 칸으로 변경
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int tmp;
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            cin >> tmp;
            pair<int, int> tmp_pair;
            if (tmp == 0) // 만약 빈 칸이라면
            {
                tmp_pair.first = x;        // 빈 칸의 x좌표
                tmp_pair.second = y;       // 빈 칸의 y좌표
                zeros.push_back(tmp_pair); // 빈 칸의 좌표를 모으는 벡터에 저장
            }
            board[y][x] = tmp;
        }
    }

    sudoku(0); // 첫 번째 빈 칸부터 시작

    return 0;
}