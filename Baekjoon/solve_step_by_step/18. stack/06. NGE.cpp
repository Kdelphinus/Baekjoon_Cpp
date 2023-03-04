/**
 * @file 06. NGE.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-18 14:57:40
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void nge(int num)
{
    int max_num = 0;
    stack<int> st;              // ����
    vector<int> number(num, 0); // �־��� �迭
    vector<int> anw(num, 0);    // ��ū���� ������ �迭
    for (int i = 0; i < num; i++)
        cin >> number[i];

    for (int i = num - 1; i >= 0; i--) // �ڿ������� Ȯ��
    {
        while (st.size() > 0 && st.top() <= number[i]) // ���ÿ� ���� �ְ� ������ ������ ���� ���� �� ũ�ٸ�
            st.pop();                                  // ���ش�

        if (st.empty()) // ���� ������ ��� ��ū���� ���� ��
            anw[i] = -1;
        else // ������ ������� ������ ���� ���� ���� ��ū���̴�
            anw[i] = st.top();

        st.push(number[i]); // ���� ���� �߰�
    }

    for (int i = 0; i < num; i++)
        cout << anw[i];
}

int main()
{
    int num;
    cin >> num;
    nge(num);
    return 0;
}