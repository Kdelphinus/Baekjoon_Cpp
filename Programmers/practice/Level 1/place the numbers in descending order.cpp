#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n)
{
    long long answer = 0;
    vector<int> nums;
    while (n > 0)
    {
        nums.push_back(n % 10);
        n /= 10;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
        answer += nums[i] * pow(10, i);

    return answer;
}

// ------------------------------------------------------

/* 다른 풀이
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

long long solution(long long n)
{
    long long answer = 0;

    string str = to_string(n);
    sort(str.begin(), str.end(), greater<char>());
    answer = stoll(str);

    return answer;
}
*/