#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int num, tmp;
	std::vector<int> numbers;
	std::vector<int>::iterator vec_it;

	std::scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		std::scanf("%d", &tmp);
		numbers.push_back(tmp);
	}
	sort(numbers.begin(), numbers.end());
	for (vec_it = numbers.begin(); vec_it != numbers.end(); vec_it++) {
		std::printf("%d\n", *vec_it);
	}

	return 0;
}