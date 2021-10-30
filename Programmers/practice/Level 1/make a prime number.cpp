#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int prime[1000 + 999 + 998 + 1] = {};
    prime[0] = 1;
    prime[1] = 1;
    for (int i = 2; i < 1000 + 999 + 998 + 1; i++)
    {
        if (prime[i] == 0)
        {
            int tmp = i * 2;
            while (tmp < 1000 + 999 + 998 + 1)
            {
                prime[tmp] = 1;
                tmp += i;
            }
        }
    }

    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (prime[nums[i] + nums[j] + nums[k]] == 0)
                    answer++;
            }
        }
    }

    return answer;
}