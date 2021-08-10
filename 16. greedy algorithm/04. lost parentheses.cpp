/**
 * @file 04. lost parentheses.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-10 11:19:01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>

using namespace std;

int min_value(string eq)
{
    int anw = 0;
    string tmp = "";
    bool flag = false;
    for (int i = 0; i < eq.length(); i++)
    {
        if (flag) // -�� �� ���̶� ������ �ڿ� ��� ���ڴ� ����� �ּڰ��̴�
        {
            if (eq[i] == '-' || eq[i] == '+')
            {
                anw -= stoi(tmp);
                tmp = "";
            }
            else
                tmp += eq[i];
        }
        else
        {
            if (eq[i] == '-')
            {
                flag = true;
                anw += stoi(tmp);
                tmp = "";
            }
            else if (eq[i] == '+')
            {
                anw += stoi(tmp);
                tmp = "";
            }
            else
                tmp += eq[i];
        }
    }

    // ������ ���ڵ� ������ش�
    if (flag)
        anw -= stoi(tmp);
    else
        anw += stoi(tmp);

    return anw;
}

int main()
{
    string eq;
    cin >> eq;
    cout << min_value(eq);
    return 0;
}