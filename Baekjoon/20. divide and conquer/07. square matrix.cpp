/**
 * @file 07. square matrix.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief ��ü�� �ƶ��� 4�� ������ ����
 * @date 2021-08-20 17:25:44
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

long long mod = 1000;
vector<vector<long long>> matrix;
vector<vector<long long>> origin;

// ���� ũ���� ����� ���ϴ� ���
void multiplication(int n)
{
    vector<vector<long long>> result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            long long num = 0;
            for (int h = 0; h < n; h++)
                num += (matrix[i][h] * matrix[h][j]) % mod;
            result[i][j] = num % mod;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            matrix[i][j] = result[i][j];
    }
}

void square(int n, long long cnt)
{
    if (cnt == 1) // 1�� ���ϸ� �ڱ��ڽ�
        return;

    square(n, cnt / 2);
    multiplication(n);

    if (cnt % 2)
    {
        vector<vector<long long>> result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                long long num = 0;
                for (int h = 0; h < n; h++)
                    num += (matrix[i][h] * origin[h][j]) % mod;
                result[i][j] = num % mod;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                matrix[i][j] = result[i][j];
        }
    }
}

int main()
{
    int n;
    long long cnt;
    cin >> n >> cnt;

    for (int i = 0; i < n; i++)
    {
        vector<long long> tmp(n, 0);
        for (int j = 0; j < n; j++)
            cin >> tmp[j];
        origin.push_back(tmp);
        matrix.push_back(tmp);
    }

    square(n, cnt);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] % mod << " ";
        cout << "\n";
    }
    return 0;
}
