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
    cin >> pare; // 괄호들을 받는다
    for (int i = 0; i < pare.size(); i++)
    {
        if (pare[i] == '(') // 여는 괄호면 스택에 저장하고
            arr.push(pare[i]);
        else // 닫는 괄호면
        {
            if (arr.empty()) // 스택이 비어있으면 vps가 아니다
                return "NO";
            else // 스택에 여는 괄호가 있다면 하나를 빼준다
                arr.pop();
        }
    }

    if (arr.empty()) // 다 확인했을 때, 스택이 비어있다면 vps이고
        return "YES";
    else // 스택에 괄호가 남아있다면 vps가 아니다
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