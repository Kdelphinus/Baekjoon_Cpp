#include <iostream>

int main() {
	int a, b, c, d, e, f;

	std::scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	for (int y = -999; y < 1000; y++) {
		for (int x = -999; x < 1000; x++) {
			if (a * x + b * y == c && d * x + e * y == f) {
				std::printf("%d %d\n", x, y);
				return 0;
			}
		}
	}
	return 1;
}