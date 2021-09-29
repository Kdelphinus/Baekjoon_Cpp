#include <iostream>

int cnt;               // �̵��� Ƚ������ �迭�� ����
int move[10000000][2]; // �̵��� ������ ���� �迭

void hanoi(int n, int start, int end)
{
    if (n == 0) // �ű� ������ ������ ����
        return;

    int mid = 6 - end - start; // ��������� ���������� �ƴ� ��
    hanoi(n - 1, start, mid);  // ���� ���� ������ ������ ������ ������ mid�� ����
    move[cnt][0] = start;      // ������ �ű�, ������� ����
    move[cnt++][1] = end;      // ������ �ű�, �������� ����
    hanoi(n - 1, mid, end);    // ������ ������ mid���� ������������ ����
}

int main()
{
    int n;
    scanf("%d", &n);
    hanoi(n, 1, 3);

    printf("%d\n", cnt);          // �̵�Ƚ�� ���
    for (int i = 0; i < cnt; i++) // �̵���� ���
        printf("%d %d\n", move[i][0], move[i][1]);

    return 0;
}