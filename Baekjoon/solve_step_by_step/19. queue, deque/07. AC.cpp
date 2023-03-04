/**
 * @file 07. AC.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-19 22:21:17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <deque>
#include <string>

using namespace std;

string ac(string order, int num, string arr)
{
    int idx = 0, flag = 0, r_cnt = 1;
    string tmp;
    deque<int> numbers;
    while (idx < arr.size()) // 문자 중에 숫자만 뽑아 큐로 만들기
    {
        if (arr[idx] != '[' && arr[idx] != ',' && arr[idx] != ']')
        {
            tmp += arr[idx];
            while (idx + 1 < arr.size() && arr[idx + 1] != '[' && arr[idx + 1] != ',' && arr[idx + 1] != ']')
                tmp += arr[++idx];
            numbers.push_back(stoi(tmp));
            tmp = "";
        }
        idx++;
    }

    idx = 0;
    while (idx < order.size()) // 명령 수행
    {
        if (order[idx] == 'R') // 뒤집을 때
        {
            while (idx + 1 < order.size() && order[idx + 1] == 'R') // 연속으로 몇 번 뒤집는지 확인
            {
                idx++;
                r_cnt++;
            }
            if (r_cnt % 2) // 홀수번 뒤집으면 뒤집음, 짝수번 뒤집으면 처음 상태와 동일
            {
                if (flag)     // 뒤집혀있다면
                    flag = 0; // 다시 원상복귀
                else          // 안 뒤집혀있다면
                    flag = 1; // 뒤집음
            }
            r_cnt = 1; // 값 초기화
        }

        if (order[idx] == 'D') // 삭제할 때
        {
            if (numbers.size() == 0) // 남아있는 숫자가 없다면 error
                return "error";

            if (flag) // 뒤집혀있다면 뒤에 것을 제거
                numbers.pop_back();
            else // 원래대로라면 앞에 것을 제거
                numbers.pop_front();
        }
        idx++;
    }

    tmp = "["; // 괄호 열기
    if (flag)  // 뒤집혀 있다면 뒤에서부터 출력
    {
        for (int i = numbers.size() - 1; i >= 0; i--)
        {
            tmp += to_string(numbers[i]);
            if (i > 0)
                tmp += ",";
        }
    }
    else // 원래대로라면 앞에서부터 출력
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            tmp += to_string(numbers[i]);
            if (i < numbers.size() - 1)
                tmp += ",";
        }
    }
    tmp += "]"; // 괄호 닫기

    return tmp;
}

int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        int num;
        string order, arr;
        cin >> order >> num >> arr;
        cout << ac(order, num, arr) << '\n';
    }
    return 0;
}