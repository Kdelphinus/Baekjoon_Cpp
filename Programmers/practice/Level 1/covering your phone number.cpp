/**
 * @file covering your phone number.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-10-28 19:52:39
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number)
{
    string answer = "";
    for (int i = 0; i < phone_number.size(); i++)
    {
        // �ڿ��� 4�ڸ� �ȿ� ���ٸ�
        if (phone_number.size() - i <= 4)
            answer += phone_number[i];
        else
            answer += '*';
    }
    return answer;
}
