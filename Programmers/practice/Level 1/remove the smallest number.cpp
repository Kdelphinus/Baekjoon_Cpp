#include <algorithm>
#include <vector>

using namespace std;

bool desc(int a, int b)
{
    return a > b;
}

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    if (arr.size() == 1)
        return {-1};

    int min_num = *min_element(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (min_num == arr[i])
            continue;
        answer.push_back(arr[i]);
    }

    return answer;
}