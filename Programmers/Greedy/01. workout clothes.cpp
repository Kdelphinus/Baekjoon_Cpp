#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    // 초기 설정
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 학생 수만큼 크기를 가지는 배열 생성, 모두 1벌씩 가지고 있다고 가정
    int student[n + 2];
    fill(student, student + n + 2, 1);

    // 계산 편의를 위해 0번, n + 1번 학생도 생성
    student[0] = 0;
    student[n + 1] = 0;

    // 도둑맞은 학생
    for (int i = 0; i < lost.size(); i++)
        student[lost[i]]--;

    // 여벌을 가지고 있는 학생
    for (int i = 0; i < reserve.size(); i++)
        student[reserve[i]]++;

    for (int i = 1; i <= n; i++)
    {
        if (student[i] == 0) // 도둑맞은 학생일 때
        {
            if (student[i - 1] > 1) // 앞 사람이 여벌이 있다면 빌림
            {
                student[i - 1]--;
                student[i]++;
                answer++;
            }
            else if (student[i + 1] > 1) // 앞 사람은 없는데 뒷 사람이 있다면 뒷 사람에게 빌림
            {
                student[i + 1]--;
                student[i]++;
                answer++;
            }
        }
        else // 체육복이 있는 학생
            answer++;
    }

    return answer;
}