#include <iostream>

int main() {
	int num, ans = 2147483647;
	std::cin >> num;
	
	for (int five = num / 5; five >= 0; five--) {
		int tmp = num - five * 5;
		if (tmp % 3 == 0) {
			ans = std::min(ans, five + tmp / 3);
		}
	}
	if (ans == 2147483647)
		std::cout << -1 << std::endl;
	else
		std::cout << ans << std::endl;
	return 0;
}