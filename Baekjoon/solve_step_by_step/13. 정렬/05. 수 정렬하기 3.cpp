#include <iostream>

int main() {
	int n, tmp;
	int num_cnt[10001] = {0,};

	std::scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		std::scanf("%d", &tmp);
		num_cnt[tmp]++;
	}

	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < num_cnt[i]; j++) {
			std::printf("%d\n", i);
		}
	}

	return 0;
}