#include <cmath>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    int sq = sqrt(n);

    for (int i = 1; i <= sq; i++)
    {
        if (n % i == 0)
        {
            answer += i;
            if (i != n / i)
                answer += n / i;
        }
    }

    return answer;
}