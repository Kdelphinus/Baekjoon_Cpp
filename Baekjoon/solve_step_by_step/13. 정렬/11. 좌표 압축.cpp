#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> numbers(n);

	for (int i = 0; i < n; i++) {
		std::cin >> numbers[i];
	}

	std::vector<int> copy(numbers);
	std::sort(copy.begin(), copy.end());
	copy.erase(std::unique(copy.begin(), copy.end()), copy.end());
	for (int i = 0; i < n; i++) {
		std::cout << std::lower_bound(copy.begin(), copy.end(), numbers[i]) - copy.begin() << " ";
	}
	std::cout << "\n";
	return 0;
}