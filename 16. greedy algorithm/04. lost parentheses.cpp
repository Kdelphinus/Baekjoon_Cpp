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
        if (flag) // -가 한 번이라도 나오면 뒤에 모든 숫자는 빼줘야 최솟값이다
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

    // 마지막 숫자도 계산해준다
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