/**
 * @file 03. parenthesis.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-17 20:06:19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string vps()
{
    string pare;
    stack<char> arr;
    cin >> pare; // ��ȣ���� �޴´�
    for (int i = 0; i < pare.size(); i++)
    {
        if (pare[i] == '(') // ���� ��ȣ�� ���ÿ� �����ϰ�
            arr.push(pare[i]);
        else // �ݴ� ��ȣ��
        {
            if (arr.empty()) // ������ ��������� vps�� �ƴϴ�
                return "NO";
            else // ���ÿ� ���� ��ȣ�� �ִٸ� �ϳ��� ���ش�
                arr.pop();
        }
    }

    if (arr.empty()) // �� Ȯ������ ��, ������ ����ִٸ� vps�̰�
        return "YES";
    else // ���ÿ� ��ȣ�� �����ִٸ� vps�� �ƴϴ�
        return "NO";
}

int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
        cout << vps() << '\n';
    return 0;
}