#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ') // ������ �ƴ� ���ڸ� ��ȯ
        {
            if (s[i] > 'Z') // �ҹ����� ��
            {
                if (s[i] + n > 'z') // ��ȯ�Ͽ� ���ĺ��� �Ѿ ��
                    s[i] -= 26 - n;
                else // ��ȯ�Ͽ� ���ĺ��� �ѱ��� ������ �׳� ����
                    s[i] += n;
            }
            else if (s[i] + n > 'Z') // ��ȯ�Ͽ� ���ĺ��� �Ѿ ��
                s[i] -= 26 - n;
            else // ��ȯ�Ͽ� ���ĺ��� �ѱ��� ������ �׳� ����
                s[i] += n;
        }
    }
    return s;
}