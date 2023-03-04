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
        if (number) // 0�� �ƴϸ� ���� �ְ�
            st.push(number);
        else // 0�̸� ���� ����
            st.pop();
    }

    int anw = 0;
    while (st.size()) // ���� �ȿ� �ִ� ��� ���� �� ������ �ݺ�
    {
        anw += st.top(); // ������ ���� ���ϰ�
        st.pop();        // ���� ����
    }

    cout << anw;

    return 0;
}