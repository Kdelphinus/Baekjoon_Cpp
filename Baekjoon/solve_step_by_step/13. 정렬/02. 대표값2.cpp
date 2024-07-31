#include <iostream>
#include <algorithm>

int main() {
	int sum = 0;
	int numbers[5];

	for (int i = 0; i < 5; i++) {
		std::scanf("%d", &numbers[i]);
		sum += numbers[i];
	}
	std::sort(numbers, numbers + 5);
	std::printf("%d\n%d\n", sum / 5, numbers[2]);

	return 0;
}