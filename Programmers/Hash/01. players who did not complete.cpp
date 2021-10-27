#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    // 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    // 하나씩 비교, 다르면 그 사람이 완주하지 못한 사람
    for (int i = 0; i < participant.size() - 1; i++)
        if (participant[i] != completion[i])
            return participant[i];

    // 위에서 다른 사람이 나오지 않으면 마지막 사람이 완주하지 못한 사람
    return participant[participant.size() - 1];
}