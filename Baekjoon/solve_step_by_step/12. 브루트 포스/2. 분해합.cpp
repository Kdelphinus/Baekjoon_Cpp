#include <iostream>

int decompose_sum(int num) {
	int create_num = 1;

	while (create_num < num) {
		int decompose = create_num;
		int tmp = create_num;
		while (tmp) {
			decompose += tmp % 10;
			tmp /= 10;
		}
		if (decompose == num)
			return create_num;
		++create_num;
	}
	return 0;
}

int main() {
	int num;

	std::scanf("%d", &num);
	std::printf("%d\n", decompose_sum(num));
}