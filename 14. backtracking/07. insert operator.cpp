/**
 * @file 07. insert operator.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-03 16:29:10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> number;
int oper[4]; // +, -, *, /의 개수
int sum, num;
int min_value = 1000000000, max_value = -1000000000;

void insert(int n)
{
    if (num == n) // 모든 연산자를 사용했다면
    {
        if (sum < min_value) // 최솟값 최신화
            min_value = sum;
        if (sum > max_value) // 최댓값 최신화
            max_value = sum;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (oper[i]) // 아직 사용할 연산자가 남아있다면
        {
            int tmp = sum; // 계산 전 값을 저장하고 연산에 맞게 계산
            if (i == 0)
                sum += number[n];
            else if (i == 1)
                sum -= number[n];
            else if (i == 2)
                sum *= number[n];
            else
                sum /= number[n];
            oper[i]--;     // 연산자를 사용헀으므로 하나 빼주고
            insert(n + 1); // 다음 계산으로 이동
            oper[i]++;     // 다 계산하고 돌아왔다면 다시 연산자를 더해주고
            sum = tmp;     // 계산 전 값으로 sum을 변경
        }
    }
}

int main()
{
    int tmp;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        number.push_back(tmp);
    }

    for (int i = 0; i < 4; i++)
        cin >> oper[i];

    sum = number[0]; // 첫 값은 연산자와 상관없이 동일
    insert(1);
    cout << max_value << "\n"
         << min_value;
    return 0;
}