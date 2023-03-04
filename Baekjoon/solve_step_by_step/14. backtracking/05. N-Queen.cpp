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

void queen(int i) // i�� �������� �ǹ�
{
    if (i == num) // ��� �ٸ��� ���� �ϳ��� ���ٸ� ����
    {
        cnt++;
        return;
    }

    for (int j = 0; j < num; j++) // ���δ� i������ ����, �������� �ϳ��� ���캸�� ���� �� �ִ� ���� ã��
    {
        if (height[j] == 0 && left_cross[i - j + num - 1] == 0 && right_cross[i + j] == 0) // ����, �¿� �밢���� ��� ���� ���ٸ�(���δ� �Լ��� i�� ����� �̹� ��ġ�� ����)
        {
            // ����, �¿� �밢���� ���� ���� �ȵ��� ǥ��
            height[j] = 1;
            left_cross[i - j + num - 1] = 1;
            right_cross[i + j] = 1;

            // ���� �����ٷ� �̵�
            queen(i + 1);

            // �� Ȯ�������� �ٽ� ���� ��
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