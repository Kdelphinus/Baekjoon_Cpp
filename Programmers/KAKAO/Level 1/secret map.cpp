/**
 * @file secret map.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 2018 KAKAO BLIND RECRUITMENT
 * @date 2021-11-03 18:50:40
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    // arr1�� ������ ���������� �ٲپ� answer�� ����
    for (int i = 0; i < arr1.size(); i++)
    {
        int num = arr1[i];
        string tmp = "";
        for (int j = 0; j < n; j++)
            tmp += ' ';

        int idx = n - 1;
        while (num > 0)
        {
            if (num % 2 == 1)
                tmp[idx] = '#';
            num /= 2;
            idx--;
        }
        answer.push_back(tmp);
    }

    // arr2�� ������ �������� �ٲٰ� answer�� ����
    for (int i = 0; i < arr2.size(); i++)
    {
        int num = arr2[i];
        int idx = n - 1;
        while (num > 0)
        {
            if (num % 2 == 1 && answer[i][idx] == ' ')
                answer[i][idx] = '#';
            num /= 2;
            idx--;
        }
    }
    return answer;
}