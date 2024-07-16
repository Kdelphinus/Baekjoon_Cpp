#include <iostream>

bool is_title(int title) {
	int check = 0;
	while (title > 0 && check != 3) {
		if (title % 10 == 6)
			check++;
		else
			check = 0;
		title /= 10;
	}
	return check == 3;
}

int main() {
	int num;
	int cnt = 0, title = 666;

	std::cin >> num;
	while (true) {
		if (is_title(title)) {
			cnt++;
			if (num == cnt) {
				std::cout << title << std::endl;
				return 0;
			}
		}
		title++;
	}
}
