#include <iostream>
#include <algorithm>

int main() {
	int n;
	int numbers[1001];

	std::scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		std::scanf("%d", &numbers[i]);
	}
	std::sort(numbers, numbers + n);
	for (int i = 0; i < n; i++) {
		std::printf("%d\n", numbers[i]);
	}

	return 0;
}