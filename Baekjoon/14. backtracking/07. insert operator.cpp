/**
 * @file 07. insert operator.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-03 16:29:10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> number;
int oper[4]; // +, -, *, /�� ����
int sum, num;
int min_value = 1000000000, max_value = -1000000000;

void insert(int n)
{
    if (num == n) // ��� �����ڸ� ����ߴٸ�
    {
        if (sum < min_value) // �ּڰ� �ֽ�ȭ
            min_value = sum;
        if (sum > max_value) // �ִ� �ֽ�ȭ
            max_value = sum;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (oper[i]) // ���� ����� �����ڰ� �����ִٸ�
        {
            int tmp = sum; // ��� �� ���� �����ϰ� ���꿡 �°� ���
            if (i == 0)
                sum += number[n];
            else if (i == 1)
                sum -= number[n];
            else if (i == 2)
                sum *= number[n];
            else
                sum /= number[n];
            oper[i]--;     // �����ڸ� ��������Ƿ� �ϳ� ���ְ�
            insert(n + 1); // ���� ������� �̵�
            oper[i]++;     // �� ����ϰ� ���ƿԴٸ� �ٽ� �����ڸ� �����ְ�
            sum = tmp;     // ��� �� ������ sum�� ����
        }
    }
}

int main()
{
    int tmp;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        number.push_back(tmp);
    }

    for (int i = 0; i < 4; i++)
        cin >> oper[i];

    sum = number[0]; // ù ���� �����ڿ� ������� ����
    insert(1);
    cout << max_value << "\n"
         << min_value;
    return 0;
}