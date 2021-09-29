#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void stack_array(int num)
{
    int check = 0, idx = 0, guide_idx = 0, target = num;
    stack<int> st;              // ����� ����
    vector<char> oper;          // �����ڰ� ����� �迭
    vector<int> number(num, 0); // �־��� �迭
    vector<int> guide(num, 0);  // ���������� �迭
    for (int i = 0; i < num; i++)
    {
        cin >> number[i];
        guide[i] = i + 1;
    }

    while (1)
    {
        if (st.empty() || number[idx] != st.top()) // ������ ����ְų� pop�� ���� �ƴ� ��
        {
            if (guide_idx == num) // guide�� �̹� �� ���Ҵٸ� ���������� �Ұ��ϴ�
            {
                cout << "NO";
                return;
            }
            st.push(guide[guide_idx++]); // ���������� �迭�� �ְ�
            oper.push_back('+');         // push ��� ǥ��
        }
        else // ���ÿ� �ִ� ���� pop�ؾ� �� ����
        {
            oper.push_back('-'); // pop�� ǥ���ϰ�
            st.pop();            // pop�ϰ�
            idx++;               // ���� ���� �Ѿ��
        }

        if (idx == num) // �־��� �迭�� �� ������ ��
        {
            if (st.empty()) // ������ ����ִٸ� ����
            {
                for (int i = 0; i < oper.size(); i++)
                    cout << oper[i] << '\n';
                return;
            }
            else // ������ �����ִٸ� ����
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