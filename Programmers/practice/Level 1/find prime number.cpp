#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(int n)
{
    vector<int> number(n + 1, 1);
    int sq = sqrt(n);
    number[0] = 0;
    number[1] = 0;
    for (int i = 2; i <= sq; i++)
    {
        if (number[i] == 1)
        {
            int tmp = i * 2;
            while (tmp <= n)
            {
                number[tmp] = 0;
                tmp += i;
            }
        }
    }

    return accumulate(number.begin(), number.end(), 0);
}