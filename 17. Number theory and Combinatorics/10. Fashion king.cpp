#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long fashion(int num)
{
    string str1, str2;
    vector<string> strs;
    vector<string> kinds;
    vector<int> kind_num;

    for (int i = 0; i < num; i++)
    {
        cin >> str1 >> str2;
        strs.push_back(str1);
    }

    for (int i = 0; i < num; i++)
    {
        if (find(kinds.begin(), kinds.end(), strs[i]) == kinds.end())
        {
        }
    }
}

int main()
{
    int test;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        int num;
        cin >> num;
        cout << fashion(num);
    }
    return 0;
}