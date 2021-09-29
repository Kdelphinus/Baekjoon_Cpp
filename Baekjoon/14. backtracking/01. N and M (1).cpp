/**
 * @file 01. N and M (1).cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-31 00:15:28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr; // ����� ���� ���� ����
int check[9];    // �� ���� �̹� ���Ϳ� ������ Ȯ���� ����Ʈ

void permutation(int n, int m)
{
    if (arr.size() == m) // ������ ���ϴ¸�ŭ ���� á�ٸ�
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (check[i] == 0) // ���� ���Ϳ� ���� ���� ���̸�
        {
            check[i] = 1;      // �־��ٰ� ǥ��
            arr.push_back(i);  // ���Ϳ� ����
            permutation(n, m); // ���� ���� �̵�
            check[i] = 0;      // ���� ����°� ������ �ٽ� ������ ǥ��
            arr.pop_back();    // ������ ����
        }
    }
}

int main()
{
    int n, m; // 1 ~ n�� ���� m���� ���������, �� �ߺ��� �� ��
    cin >> n >> m;
    permutation(n, m);
    return 0;
}