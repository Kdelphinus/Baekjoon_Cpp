#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void stack_array(int num)
{
    int check = 0, idx = 0, guide_idx = 0, target = num;
    stack<int> st;              // 사용할 스택
    vector<char> oper;          // 연산자가 저장될 배열
    vector<int> number(num, 0); // 주어진 배열
    vector<int> guide(num, 0);  // 오름차순된 배열
    for (int i = 0; i < num; i++)
    {
        cin >> number[i];
        guide[i] = i + 1;
    }

    while (1)
    {
        if (st.empty() || number[idx] != st.top()) // 스택이 비어있거나 pop할 때가 아닐 때
        {
            if (guide_idx == num) // guide를 이미 다 돌았다면 오름차순이 불가하다
            {
                cout << "NO";
                return;
            }
            st.push(guide[guide_idx++]); // 오름차순된 배열을 넣고
            oper.push_back('+');         // push 사용 표시
        }
        else // 스택에 있는 것이 pop해야 할 때면
        {
            oper.push_back('-'); // pop을 표시하고
            st.pop();            // pop하고
            idx++;               // 다음 수로 넘어간다
        }

        if (idx == num) // 주어진 배열을 다 돌았을 때
        {
            if (st.empty()) // 스택이 비어있다면 성공
            {
                for (int i = 0; i < oper.size(); i++)
                    cout << oper[i] << '\n';
                return;
            }
            else // 스택이 남아있다면 실패
            {
                cout << "NO";
                return;
            }
        }
    }
}

int main()
{
    int num;
    cin >> num;
    stack_array(num);
    return 0;
}