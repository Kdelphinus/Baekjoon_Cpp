#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int i;

bool cmp(string a, string b)
{
    if (a[i] == b[i]) // ���ϰ��� �ϴ� ���ڰ� ������ ��ü ���ڿ� ��
        return a < b;
    else
        return a[i] < b[i]; // ���ϴ� ���ڿ��� �ٸ��� �� ���ڿ��� ��

    // ���� ���ǹ��� �� �ٷ� ǥ���� ��
    // return a[i] == b[i] ? a < b : a[i] < b[i];
}

vector<string> solution(vector<string> strings, int n)
{
    i = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}