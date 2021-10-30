#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ') // 공백이 아닌 문자만 변환
        {
            if (s[i] > 'Z') // 소문자일 때
            {
                if (s[i] + n > 'z') // 변환하여 알파벳을 넘어갈 때
                    s[i] -= 26 - n;
                else // 변환하여 알파벳을 넘기지 않으면 그냥 진행
                    s[i] += n;
            }
            else if (s[i] + n > 'Z') // 변환하여 알파벳을 넘어갈 때
                s[i] -= 26 - n;
            else // 변환하여 알파벳을 넘기지 않으면 그냥 진행
                s[i] += n;
        }
    }
    return s;
}