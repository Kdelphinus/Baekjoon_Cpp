#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        // 자를 벡터를 담을 벡터
        vector<int> tmp(commands[i][1] - commands[i][0] + 1);

        // 벡터를 잘라 복사
        copy(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1], tmp.begin());

        // 자른 벡터 정렬
        sort(tmp.begin(), tmp.end());

        // 답을 찾아 벡터에 삽입
        answer.push_back(tmp[commands[i][2] - 1]);
    }

    return answer;
}