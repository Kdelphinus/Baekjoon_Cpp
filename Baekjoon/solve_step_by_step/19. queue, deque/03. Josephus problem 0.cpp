/**
 * @file 03. Josephus problem 0.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-18 16:34:31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void josephus(int num, int k)
{
    int tmp;
    queue<int> q;
    vector<int> arr;
    for (int i = 1; i <= num; i++) // 초기 배열
        q.push(i);

    while (q.size() > 0) // 다 확인할 때까지 반복
    {
        for (int i = 0; i < k - 1; i++) // k번째 전 숫자들은 뒤로 옮긴다
        {
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }

        arr.push_back(q.front()); // k번째 수는 따로 저장하고
        q.pop();                  // 뺀다
    }

    cout << "<";
    for (int i = 0; i < num - 1; i++)
        cout << arr[i] << ", ";
    cout << arr[num - 1] << ">";
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num, k;
    cin >> num >> k;
    josephus(num, k);
    return 0;
}