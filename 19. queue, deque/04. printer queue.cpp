/**
 * @file 04. printer queue.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-18 16:58:50
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b) // ���������� ���� �Լ�
{
    return a > b;
}

int printer(int num, int check)
{
    int tmp, idx = 0, cnt = 1;
    queue<int> q;
    vector<int> value;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        q.push(tmp);
        value.push_back(tmp);
    }

    sort(value.begin(), value.end(), desc); // �߿䵵 ������ ����

    while (1)
    {
        if (q.front() == value[idx]) // ���� ���� ������ �� �տ� �ִٸ�
        {
            if (check == 0) // �ٵ� �װ��� �츮�� �˰� ���� ���̶��
                return cnt; // �̴� ������ ����

            // �츮�� �˰� ���� ���� �ƴ϶��
            q.pop(); // ������ ����ϰ�
            idx++;   // �������� ���� ������ �̵�
            check--; // �츮�� �˰� ���� ������ ��ġ ������Ʈ
            cnt++;   // ���� Ƚ�� �߰�
        }
        else // ���� ���� ������ �ƴ϶��
        {
            tmp = q.front(); // �տ� �ִ� ������
            q.pop();         // ����
            q.push(tmp);     // �ڷ� �ű��

            if (check == 0)           // �� ���� ������ �츮�� ���Ѵ� ������
                check = q.size() - 1; // �� �ڿ� ��ġ�� ������ ��ġ�� �����ϰ�
            else                      // �ƴ϶��
                check--;              // ������ �ϳ� �ű��
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        int num, check;
        cin >> num >> check;
        cout << printer(num, check) << '\n';
    }
    return 0;
}