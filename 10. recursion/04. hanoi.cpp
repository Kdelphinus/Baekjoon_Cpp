#include <iostream>

int cnt;               // 이동한 횟수이자 배열의 길이
int move[10000000][2]; // 이동한 순서를 담을 배열

void hanoi(int n, int start, int end)
{
    if (n == 0) // 옮길 원판이 없으면 종료
        return;

    int mid = 6 - end - start; // 출발지점과 도착지점이 아닌 곳
    hanoi(n - 1, start, mid);  // 가장 밑의 원판을 제외한 나머지 원판을 mid로 보냄
    move[cnt][0] = start;      // 원판을 옮김, 출발지점 저장
    move[cnt++][1] = end;      // 원판을 옮김, 도착지점 저장
    hanoi(n - 1, mid, end);    // 나머지 원판을 mid에서 도착지점으로 보냄
}

int main()
{
    int n;
    scanf("%d", &n);
    hanoi(n, 1, 3);

    printf("%d\n", cnt);          // 이동횟수 출력
    for (int i = 0; i < cnt; i++) // 이동경로 출력
        printf("%d %d\n", move[i][0], move[i][1]);

    return 0;
}