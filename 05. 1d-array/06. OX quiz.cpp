/**
 * @file 06. OX quiz.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-17 16:02:06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>

int main()
{
    int t; // test ����
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int len, bonus = 0, score = 0;
        std::string anw; // ä�� ����� ����
        std::cin >> anw;
        len = anw.length(); // ä�� ��� ����

        for (int i = 0; i < len; i++)
        {
            if (anw[i] == 'O') // �¾�����
            {
                score += bonus + 1; // �⺻ ���� 1���� ���ʽ� ������ ������
                bonus++;            // �̹� ������ ����⿡ ���ʽ� ���� 1�� �߰�
            }
            else           // Ʋ�ȴٸ�
                bonus = 0; // ���ʽ� ���� �ʱ�ȭ
        }
        std::cout << score << std::endl;
    }
    return 0;
}