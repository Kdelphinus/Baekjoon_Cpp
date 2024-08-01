#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	int n, m, tmp;
	unordered_map<int, int> cards;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		cards[tmp] = 1;
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);
		if (cards.find(tmp) == cards.end())
			printf("0 ");
		else
			printf("1 ");
	}
	return 0;
}