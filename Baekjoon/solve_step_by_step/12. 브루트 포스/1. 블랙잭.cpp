#include <iostream>

int main() {
	int n, m, tmp, max = 0;
	int cards[101];

	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> tmp;
		cards[i] = tmp;
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = cards[i] + cards[j] + cards[k];
				if (sum < m && sum > max)
					max = sum;
				if (sum == m) {
					std::cout << m << std::endl;
					return 0;
				}
			}
		}
	}
	std::cout << max << std::endl;
	return 0;
}