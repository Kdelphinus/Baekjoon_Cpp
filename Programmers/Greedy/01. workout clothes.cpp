#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    // �ʱ� ����
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // �л� ����ŭ ũ�⸦ ������ �迭 ����, ��� 1���� ������ �ִٰ� ����
    int student[n + 2];
    fill(student, student + n + 2, 1);

    // ��� ���Ǹ� ���� 0��, n + 1�� �л��� ����
    student[0] = 0;
    student[n + 1] = 0;

    // ���ϸ��� �л�
    for (int i = 0; i < lost.size(); i++)
        student[lost[i]]--;

    // ������ ������ �ִ� �л�
    for (int i = 0; i < reserve.size(); i++)
        student[reserve[i]]++;

    for (int i = 1; i <= n; i++)
    {
        if (student[i] == 0) // ���ϸ��� �л��� ��
        {
            if (student[i - 1] > 1) // �� ����� ������ �ִٸ� ����
            {
                student[i - 1]--;
                student[i]++;
                answer++;
            }
            else if (student[i + 1] > 1) // �� ����� ���µ� �� ����� �ִٸ� �� ������� ����
            {
                student[i + 1]--;
                student[i]++;
                answer++;
            }
        }
        else // ü������ �ִ� �л�
            answer++;
    }

    return answer;
}