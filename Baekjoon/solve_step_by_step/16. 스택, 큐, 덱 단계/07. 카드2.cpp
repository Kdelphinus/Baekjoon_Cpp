#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;
	queue<int> cards;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		cards.push(i);

	while (cards.size() > 1) {
		cards.pop();
		cards.push(cards.front());
		cards.pop();
	}

	printf("%d\n", cards.front());

	return 0;
}