/**
 * @file 10. Fashion king.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-16 20:12:45
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long fashion(int num)
{
    string str1, str2;
    vector<string> strs;
    long long anw = 1, tmp = 1;

    if (num == 0) // ���� ������ ���ٸ� ����� ���� 0�̴�
        return 0;

    for (int i = 0; i < num; i++)
    {
        cin >> str1 >> str2;
        strs.push_back(str2); // ������ ������
    }

    sort(strs.begin(), strs.end()); // ����
    str1 = strs[0];                 // ù��° �� ����
    for (int i = 1; i < num; i++)
    {
        if (str1 == strs[i]) // ���� ������ ���� ���� �߰�
            tmp++;
        else // �ٸ� ������ ���� ������ ����� ���� ���ϰ� ���� ������ ���� ����
        {
            anw *= (tmp + 1); // ���� ��쵵 �����Ͽ� ���
            tmp = 1;
            str1 = strs[i];
        }
    }

    anw *= (tmp + 1); // ������ ������ ���

    return anw - 1; // �� ���� ���� ����
}

int main()
{
    int test;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        int num;
        cin >> num;
        cout << fashion(num) << '\n';
    }
    return 0;
}