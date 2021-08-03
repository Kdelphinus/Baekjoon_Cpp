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
    if (n == zeros.size()) // ��� �� ĭ�� Ȯ���ߴٸ�
    {
        flag = 1;                   // ����� �� ä���ٰ� ǥ���ϰ�
        for (int y = 0; y < 9; y++) // ��� ���
        {
            for (int x = 0; x < 9; x++)
                cout << board[y][x] << " ";
            cout << "\n";
        }
        return;
    }

    if (flag) // �̹� ����� ��µǾ��ٸ� �ٷ� ����
        return;

    int x, y;
    int possible[10] = {0}; // �� ĭ�� �� �� �ִ� ���ڸ� ������ �迭
    x = zeros[n].first;     // �� ĭ�� x��ǥ
    y = zeros[n].second;    // �� ĭ�� y��ǥ

    for (int j = 0; j < 9; j++)
    {
        if (possible[board[y][j]] == 0) // ���� �� Ȯ��
            possible[board[y][j]]++;
        if (possible[board[j][x]] == 0) // ���� �� Ȯ��
            possible[board[j][x]]++;
    }

    for (int j = y / 3 * 3; j < y / 3 * 3 + 3; j++) // 3 * 3ĭ �ȿ� �ִ� ���� Ȯ��
    {
        for (int k = x / 3 * 3; k < x / 3 * 3 + 3; k++)
        {
            if (possible[board[j][k]] == 0)
                possible[board[j][k]]++;
        }
    }

    for (int j = 1; j <= 9; j++)
    {
        if (possible[j] == 0) // ������ ���ڸ�
        {
            board[y][x] = j; // ���ڸ� �ٲٰ�
            sudoku(n + 1);   // ���� �� ĭ���� �̵�
            board[y][x] = 0; // ���� ���� ���ڰ� Ʋ���ٸ� �ٽ� �� ĭ���� ����
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
            if (tmp == 0) // ���� �� ĭ�̶��
            {
                tmp_pair.first = x;        // �� ĭ�� x��ǥ
                tmp_pair.second = y;       // �� ĭ�� y��ǥ
                zeros.push_back(tmp_pair); // �� ĭ�� ��ǥ�� ������ ���Ϳ� ����
            }
            board[y][x] = tmp;
        }
    }

    sudoku(0); // ù ��° �� ĭ���� ����

    return 0;
}