/**
 * @file 06. number of words.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-20 22:09:40
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>

int main()
{
    int cnt = 0;
    std::string s;
    std::getline(std::cin, s);    // �����ִ� ���ڿ� �ޱ�
    if (s[s.length() - 1] != ' ') // �� �ڰ� ������ �ƴϸ�
        s.append(" ");            // ���� �ڿ� �ִ� �ܾ �߰��ϱ� ���� ���� �߰�

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ') // ������ ���� ������ �ܾ� ���� �߰�
        {
            if (i > 0) // ������ �� ���̸� ����
                cnt++;
        }
    }

    std::cout << cnt;

    return 0;
}