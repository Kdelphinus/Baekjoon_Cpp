// 함수만 구하는 문제
// vector 사용법을 따로 공부해야 할 듯
#include <vector>

long long sum(std::vector<int> &a)
{
    long long ans = 0;

    for (int i = 0; i < a.size(); i++)
        ans += a[i];

    return ans;
}