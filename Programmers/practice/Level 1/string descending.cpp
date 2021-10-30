#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b)
{
    return a > b;
}

string solution(string s)
{
    string answer = "";
    vector<int> str;
    for (int i = 0; i < s.size(); i++)
        str.push_back(s[i]);

    sort(str.begin(), str.end(), desc);

    for (int i = 0; i < s.size(); i++)
        answer += str[i];

    return answer;
}