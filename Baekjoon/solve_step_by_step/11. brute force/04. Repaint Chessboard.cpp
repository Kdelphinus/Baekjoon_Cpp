/**
 * @file 04. Repaint Chessboard.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-25 17:48:18
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

char board[51][51];

int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

int repainting(int n, int m)
{
    int cnt = n * m, black_cnt = 0, white_cnt = 0;
    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            // ���� ����� ���� �������� ����� ��, ĥ�ؾ� �ϴ� ���� ��
            for (int k = i; k < i + 8; k++)
            {
                for (int l = j; l < j + 8; l++)
                {
                    if ((k + l) % 2 != 0 && board[k][l] == 'B')
                        black_cnt++;
                    else if ((k + l) % 2 == 0 && board[k][l] == 'W')
                        black_cnt++;
                }
            }

            // ���� ����� ���� ������� ����� ��, ĥ�ؾ� �ϴ� ���� ��
            for (int k = i; k < i + 8; k++)
            {
                for (int l = j; l < j + 8; l++)
                {
                    if ((k + l) % 2 != 0 && board[k][l] == 'W')
                        white_cnt++;
                    else if ((k + l) % 2 == 0 && board[k][l] == 'B')
                        white_cnt++;
                }
            }
            cnt = min(cnt, min(white_cnt, black_cnt));

            white_cnt = 0;
            black_cnt = 0;
        }
    }
    return cnt;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cin >> board[i][j];
    }
    std::cout << repainting(n, m);
    return 0;
}