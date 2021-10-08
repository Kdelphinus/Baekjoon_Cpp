#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // 힙은 완전 이진 트리이고 부모 노드는 자식 노드의 데이터보다 크거나 같다
    // 그렇기에 정렬된 배열은 아니다
    // c++은 기본적으로 최대힙을 사용

    // 최대힙
    priority_queue<int, vector<int>> max_q;
    max_q.push(4);
    max_q.push(9);
    max_q.push(1);
    max_q.push(2);
    max_q.push(3);
    max_q.push(8);
    max_q.push(7);
    max_q.push(5);
    max_q.push(11);
    while (!max_q.empty())
    {
        cout << max_q.top() << ' ';
        max_q.pop();
    }
    // 11 9 8 7 5 4 3 2 1, 큰 순서대로 출력됨

    // ---------------------------------------------------------------------------
    cout << '\n';

    // 최소힙
    priority_queue<int, vector<int>, greater<int>> min_q;
    min_q.push(4);
    min_q.push(9);
    min_q.push(1);
    min_q.push(2);
    min_q.push(3);
    min_q.push(8);
    min_q.push(7);
    min_q.push(5);
    min_q.push(11);
    while (!min_q.empty())
    {
        cout << min_q.top() << ' ';
        min_q.pop();
    }
    // 1, 2, 3, 4, 5, 7, 8, 9, 11, 작은 순서대로 출력됨
    return 0;
}