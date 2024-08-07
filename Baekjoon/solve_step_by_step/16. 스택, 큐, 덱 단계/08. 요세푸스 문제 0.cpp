#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, k;
	queue<int> q;

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		q.push(i);
	printf("<");
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		printf("%d", q.front());
		q.pop();
		if (q.empty())
			printf(">\n");
		else
			printf(", ");
	}

	return 0;
}