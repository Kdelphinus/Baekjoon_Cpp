#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int i;

bool cmp(string a, string b)
{
    if (a[i] == b[i]) // 비교하고자 하는 문자가 같으면 전체 문자열 비교
        return a < b;
    else
        return a[i] < b[i]; // 비교하는 문자열이 다르면 그 문자열만 비교

    // 위의 조건문을 한 줄로 표현한 것
    // return a[i] == b[i] ? a < b : a[i] < b[i];
}

vector<string> solution(vector<string> strings, int n)
{
    i = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}