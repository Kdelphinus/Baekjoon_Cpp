#include <iostream>
#include <vector>

using namespace std;

int packing(int num, int limit)
{
    vector<vector<int>> object(num, vector<int>(num, 0));
    vector<int> dp(num, 0);

    for (int i = 0; i < num; i++)
        cin >> object[i][0] >> object[i][1];
}

int main()
{
    int num, limit;
    cin >> num >> limit;
    cout << packing(num, limit);
    return 0;
}