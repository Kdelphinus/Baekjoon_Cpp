#include <cmath>
#include <vector>

using namespace std;

long long solution(long long n)
{
    long long answer = 0;
    long long tmp = sqrt(n);

    if (tmp * tmp == n)
        return (tmp + 1) * (tmp + 1);
    return -1;
}