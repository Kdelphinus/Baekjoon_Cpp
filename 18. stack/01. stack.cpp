/**
 * @file 01. stack.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-16 20:45:02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

using namespace std;

// 스택 헤더 파일 사용
#include <stack>

int main()
{
    stack<int> st;
    int order_num;
    cin >> order_num;
    for (int i = 0; i < order_num; i++)
    {
        string order;
        cin >> order;
        if (order == "push")
        {
            int num;
            cin >> num;
            st.push(num);
        }
        else if (order == "pop")
        {
            if (st.empty())
                cout << -1 << '\n';
            else
            {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (order == "size")
            cout << st.size() << '\n';
        else if (order == "empty")
            if (st.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        else if (order == "top")
            if (st.empty())
                cout << -1 << '\n';
            else
                cout << st.top() << '\n';
        else
            cout << "없는 명령어입니다.\n";
    }

    return 0;
}

// -----------------------------------------------------------------------------------------
// 직접 구현
//#include <vector>
//vector<int> arr;

//void push(int num)
//{
//    arr.push_back(num);
//}

//int pop()
//{
//    if (arr.empty())
//        return -1;
//    int tmp = arr[arr.size() - 1];
//    arr.pop_back();
//    return tmp;
//}

//int size()
//{
//    return arr.size();
//}

//int empty()
//{
//    if (arr.empty())
//        return 1;
//    return 0;
//}

//int top()
//{
//    if (arr.empty())
//        return -1;
//    return arr[arr.size() - 1];
//}

//int main()
//{
//    int order_num;
//    cin >> order_num;
//    for (int i = 0; i < order_num; i++)
//    {
//        string order;
//        cin >> order;
//        if (order == "push")
//        {
//            int num;
//            cin >> num;
//            push(num);
//        }
//        else if (order == "pop")
//            cout << pop() << '\n';
//        else if (order == "size")
//            cout << size() << '\n';
//        else if (order == "empty")
//            cout << empty() << '\n';
//        else if (order == "top")
//            cout << top() << '\n';
//        else
//            cout << "없는 명령어입니다.\n";
//    }
//    return 0;
//}