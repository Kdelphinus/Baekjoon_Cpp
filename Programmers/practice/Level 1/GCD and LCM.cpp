#include <vector>

using namespace std;

vector<int> solution(int n, int m)
{
    int copy_n = n, copy_m = m;
    int remain;

    while (copy_m > 0)
    {
        remain = copy_n % copy_m;
        copy_n = copy_m;
        copy_m = remain;
    }

    return {copy_n, m * n / copy_n};
}