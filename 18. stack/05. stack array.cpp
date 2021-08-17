#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void stack_array(int num)
{
    int check = 0, idx = 0, target = num;
    stack<int> st;
    vector<char> oper;
    vector<int> number(num, 0);
    for (int i = 0; i < num; i++)
        cin >> number[i];

    while (check < num)
    {
        if (idx == num && st.empty())
        {
            cout << "NO";
            return;
        }

        if (st.empty() == false && target == st.top())
        {
            oper.push_back('-');
            st.pop();
            check++;
        }
        else
        {
            if (target != number[idx])
            {
                oper.push_back('+');
                st.push(number[idx]);
            }
            else
                check++;
            idx++;
        }
    }

    for (int i = 0; i < oper.size(); i++)
        cout << oper[i] << '\n';
}

int main()
{
    int num;
    cin >> num;
    stack_array(num);
    return 0;
}