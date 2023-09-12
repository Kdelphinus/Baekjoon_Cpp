#include <iostream>

int compare(const void *a, const void *b) {
	const int *x = (int *)a;
	const int *y = (int *)b;

	if (*x > *y) return 1;
	else if (*x < *y) return -1;
	return 0;
}

std::pair<int, int> fakeDwarf(int *height, int total) {
	std::pair<int, int> p;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (total == height[i] + height[j]) {
				p.first = i;
				p.second = j;
				return p;
			}
		}
	}
	return p;
}

int main() {
	int total = 0;
	int height[9];
	std::pair<int, int> fake;

	for (int i = 0; i < 9; i++) {
		std::cin >> height[i];
		total += height[i];
	}
	total -= 100;
	qsort(height, 9, sizeof(int), compare);
	fake = fakeDwarf(height, total);
	for (int i = 0; i < 9; i++) {
		if (i == fake.first || i == fake.second)
			continue;
		std::cout << height[i] << std::endl;
	}
	return 0;
}