/**
 * @file 07. AC.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-19 22:21:17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <deque>
#include <string>

using namespace std;

string ac(string order, int num, string arr)
{
    int idx = 0, flag = 0, r_cnt = 1;
    string tmp;
    deque<int> numbers;
    while (idx < arr.size()) // ���� �߿� ���ڸ� �̾� ť�� �����
    {
        if (arr[idx] != '[' && arr[idx] != ',' && arr[idx] != ']')
        {
            tmp += arr[idx];
            while (idx + 1 < arr.size() && arr[idx + 1] != '[' && arr[idx + 1] != ',' && arr[idx + 1] != ']')
                tmp += arr[++idx];
            numbers.push_back(stoi(tmp));
            tmp = "";
        }
        idx++;
    }

    idx = 0;
    while (idx < order.size()) // ��� ����
    {
        if (order[idx] == 'R') // ������ ��
        {
            while (idx + 1 < order.size() && order[idx + 1] == 'R') // �������� �� �� �������� Ȯ��
            {
                idx++;
                r_cnt++;
            }
            if (r_cnt % 2) // Ȧ���� �������� ������, ¦���� �������� ó�� ���¿� ����
            {
                if (flag)     // �������ִٸ�
                    flag = 0; // �ٽ� ���󺹱�
                else          // �� �������ִٸ�
                    flag = 1; // ������
            }
            r_cnt = 1; // �� �ʱ�ȭ
        }

        if (order[idx] == 'D') // ������ ��
        {
            if (numbers.size() == 0) // �����ִ� ���ڰ� ���ٸ� error
                return "error";

            if (flag) // �������ִٸ� �ڿ� ���� ����
                numbers.pop_back();
            else // ������ζ�� �տ� ���� ����
                numbers.pop_front();
        }
        idx++;
    }

    tmp = "["; // ��ȣ ����
    if (flag)  // ������ �ִٸ� �ڿ������� ���
    {
        for (int i = numbers.size() - 1; i >= 0; i--)
        {
            tmp += to_string(numbers[i]);
            if (i > 0)
                tmp += ",";
        }
    }
    else // ������ζ�� �տ������� ���
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            tmp += to_string(numbers[i]);
            if (i < numbers.size() - 1)
                tmp += ",";
        }
    }
    tmp += "]"; // ��ȣ �ݱ�

    return tmp;
}

int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        int num;
        string order, arr;
        cin >> order >> num >> arr;
        cout << ac(order, num, arr) << '\n';
    }
    return 0;
}