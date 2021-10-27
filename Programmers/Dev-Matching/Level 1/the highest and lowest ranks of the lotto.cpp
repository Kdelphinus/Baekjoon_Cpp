#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(int a, int b) // 내림차순
{
    return a > b;
}

int num_to_rank(int num) // 로또 순위를 알려주는 함수
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
    // 로또 번호의 인덱스, 당첨 번호의 인덱스, 모르는 번호의 개수, 최악의 경우 맞는 수
    int idx_lo = 0, idx_win = 0, zero_cnt = 0, worst = 0;

    // 내림차순, 0을 뒤로 보내기 위하여
    sort(lottos.begin(), lottos.end(), desc);
    sort(win_nums.begin(), win_nums.end(), desc);

    while (idx_lo < 6 && idx_win < 6)
    {
        // 같은 번호면 맞춘 번호
        if (lottos[idx_lo] == win_nums[idx_win])
        {
            idx_lo++;
            idx_win++;
            worst++;
        }
        // 더 큰 번호를 가진 배열을 한 칸 움직인다
        else
        {
            if (lottos[idx_lo] > win_nums[idx_win])
                idx_lo++;
            else
                idx_win++;
        }
    }

    // 알지 못하는 숫자의 개수를 구한다
    for (int i = 5; i >= 0; i--)
    {
        if (lottos[i] > 0)
            break;
        zero_cnt++;
    }

    // 최고의 경우는 최악의 경우 + 모르는 수가 모두 맞는 경우
    return {num_to_rank(zero_cnt + worst), num_to_rank(worst)};
}