/**
 * @file 06. matrix multiplication.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief Çà·ÄÀÇ °ö
 * @date 2021-08-20 16:42:27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multiplication(int n, int m, int k, vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
    vector<vector<int>> matrix3(n, vector<int>(k, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int h = 0; h < m; h++)
                matrix3[i][j] += matrix1[i][h] * matrix2[h][j];
        }
    }

    return matrix3;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> matrix1(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix1[i][j];
    }

    cin >> m >> k;
    vector<vector<int>> matrix2(m, vector<int>(k, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
            cin >> matrix2[i][j];
    }

    vector<vector<int>> matrix3;
    matrix3 = multiplication(n, m, k, matrix1, matrix2);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            cout << matrix3[i][j] << " ";
        cout << "\n";
    }
    return 0;
}