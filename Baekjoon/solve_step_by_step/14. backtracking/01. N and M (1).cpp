/**
 * @file 01. N and M (1).cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-31 00:15:28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr; // 출력할 수를 담을 벡터
int check[9];    // 그 수가 이미 벡터에 들어갔는지 확인할 리스트

void permutation(int n, int m)
{
    if (arr.size() == m) // 벡터의 원하는만큼 수가 찼다면
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (check[i] == 0) // 아직 벡터에 넣지 않은 수이면
        {
            check[i] = 1;      // 넣었다고 표시
            arr.push_back(i);  // 벡터에 넣음
            permutation(n, m); // 다음 수로 이동
            check[i] = 0;      // 조합 만드는게 끝나면 다시 뺐음을 표시
            arr.pop_back();    // 실제로 빼줌
        }
    }
}

int main()
{
    int n, m; // 1 ~ n의 수로 m개의 수열만들기, 단 중복은 안 됨
    cin >> n >> m;
    permutation(n, m);
    return 0;
}