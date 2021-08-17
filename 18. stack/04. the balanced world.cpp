/**
 * @file 04. the balanced world.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 3번 문제에서 괄호 종류만 하나더 추가
 * @date 2021-08-17 20:19:38
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string balance(string str)
{
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '[')
            st.push(str[i]);
        else if (str[i] == '(')
            st.push(str[i]);
        else if (str[i] == ']')
        {
            if (st.empty())
                return "no";

            if (st.top() == '[')
                st.pop();
            else
                return "no";
        }
        else if (str[i] == ')')
        {
            if (st.empty())
                return "no";

            if (st.top() == '(')
                st.pop();
            else
                return "no";
        }
    }

    if (st.empty())
        return "yes";
    else
        return "no";
}

int main()
{
    while (1)
    {
        string str;
        getline(cin, str);
        if (str[0] == '.' && str.size() == 1)
            break;
        cout << balance(str) << '\n';
    }
    return 0;
}