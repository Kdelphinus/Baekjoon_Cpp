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
    stack<int> st;              // 스택
    vector<int> number(num, 0); // 주어진 배열
    vector<int> anw(num, 0);    // 오큰수를 저장할 배열
    for (int i = 0; i < num; i++)
        cin >> number[i];

    for (int i = num - 1; i >= 0; i--) // 뒤에서부터 확인
    {
        while (st.size() > 0 && st.top() <= number[i]) // 스택에 수가 있고 마지막 수보다 현재 수가 더 크다면
            st.pop();                                  // 빼준다

        if (st.empty()) // 만약 스택이 비면 오큰수가 없는 것
            anw[i] = -1;
        else // 스택이 비어있지 않으면 가장 위의 수가 오큰수이다
            anw[i] = st.top();

        st.push(number[i]); // 현재 수를 추가
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