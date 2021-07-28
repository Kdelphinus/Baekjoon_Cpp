/**
 * @file 08. sort words.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-28 15:25:18
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comapare(string a, string b) // ���̼����� �����ϱ� ����
{
    if (a.length() == b.length()) // ���̰� ���ٸ�
        return a < b;             // ���ĺ� ������
    return a.length() < b.length();
}

int main()
{
    int num;
    vector<string> words;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        string str;
        cin >> str;
        if (find(words.begin(), words.end(), str) == words.end()) // �ߺ��� �ܾ�� �߰����� ����
            words.push_back(str);
    }
    sort(words.begin(), words.end(), comapare); // compare�� ���� ���ĺ� ������ ����

    for (int i = 0; i < words.size(); i++)
        cout << words[i] << "\n";

    return 0;
}