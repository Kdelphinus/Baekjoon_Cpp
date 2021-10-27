#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(int a, int b) // ��������
{
    return a > b;
}

int num_to_rank(int num) // �ζ� ������ �˷��ִ� �Լ�
{
    if (num == 6)
        return 1;
    else if (num == 5)
        return 2;
    else if (num == 4)
        return 3;
    else if (num == 3)
        return 4;
    else if (num == 2)
        return 5;
    return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    // �ζ� ��ȣ�� �ε���, ��÷ ��ȣ�� �ε���, �𸣴� ��ȣ�� ����, �־��� ��� �´� ��
    int idx_lo = 0, idx_win = 0, zero_cnt = 0, worst = 0;

    // ��������, 0�� �ڷ� ������ ���Ͽ�
    sort(lottos.begin(), lottos.end(), desc);
    sort(win_nums.begin(), win_nums.end(), desc);

    while (idx_lo < 6 && idx_win < 6)
    {
        // ���� ��ȣ�� ���� ��ȣ
        if (lottos[idx_lo] == win_nums[idx_win])
        {
            idx_lo++;
            idx_win++;
            worst++;
        }
        // �� ū ��ȣ�� ���� �迭�� �� ĭ �����δ�
        else
        {
            if (lottos[idx_lo] > win_nums[idx_win])
                idx_lo++;
            else
                idx_win++;
        }
    }

    // ���� ���ϴ� ������ ������ ���Ѵ�
    for (int i = 5; i >= 0; i--)
    {
        if (lottos[i] > 0)
            break;
        zero_cnt++;
    }

    // �ְ��� ���� �־��� ��� + �𸣴� ���� ��� �´� ���
    return {num_to_rank(zero_cnt + worst), num_to_rank(worst)};
}