/**
 * @file 02. zero.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-16 20:59:40
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int num;
    stack<int> st;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int number;
        cin >> number;
        if (number) // 0이 아니면 수를 넣고
            st.push(number);
        else // 0이면 수를 뺀다
            st.pop();
    }

    int anw = 0;
    while (st.size()) // 스택 안에 있는 모든 수를 뺄 때까지 반복
    {
        anw += st.top(); // 마지막 수를 더하고
        st.pop();        // 수를 뺀다
    }

    cout << anw;

    return 0;
}