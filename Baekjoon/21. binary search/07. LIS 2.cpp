/**
 * @file 07. LIS 2.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-08 01:31:38
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> tmp;

int binary_search(int num)
{ // �����������ִ� arr���� num�� �� �ڸ��� �̺�Ž������ ã�� �Լ�
    int start = 0, end = tmp.size() - 1;
    int index = 1000000;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (num <= tmp[mid]) // �߰����� num���� ũ�ų� ���� ��
        {
            if (index > mid)
                index = mid;
            end = mid - 1;
        }
        else // �߰����� num���� ���� ��
            start = mid + 1;
    }
    return index;
}

int LIS(int num)
{
    for (int i = 0; i < num; i++)
    {
        // tmp�� ����ְų� arr[i]�� �ڿ� �־ LIS�� ������ ��
        if (tmp.size() == 0 || tmp[tmp.size() - 1] < arr[i])
            tmp.push_back(arr[i]);
        // �ڿ� ������ LIS�� ���� ��, arr[i]�� �� �� �ִ� ��ġ�� �ִ� ���� arr[i]�� �ٲ۴�
        // ������ ������ ������ ���� ���ڰ� ���� �ȴ�
        else
            tmp[binary_search(arr[i])] = arr[i];
    }

    // tmp Ȯ�� �ڵ�, tmp�� ���̴� �������� ���ҵ��� ���� �ƴϴ�
    //for (int i = 0; i < tmp.size(); i++)
    //    cout << tmp[i] << " ";
    //cout << '\n';
    return tmp.size();
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int num, tmp_num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp_num;
        arr.push_back(tmp_num);
    }
    cout << LIS(num);

    return 0;
}