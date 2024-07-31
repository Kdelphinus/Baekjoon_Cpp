#include <iostream>
#include <algorithm>

bool desc(int a, int b) {
	return a > b;
}

int main() {
	int n, k;
	int scores[1001];

	std::scanf("%d %d\n", &n, &k);
	for (int i = 0; i < n; i++) {
		std::scanf("%d", &scores[i]);
	}

	std::sort(scores, scores + n, desc);
	std::printf("%d\n", scores[k - 1]);
	return 0;
}