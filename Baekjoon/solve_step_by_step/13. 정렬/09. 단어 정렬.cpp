#include <iostream>
#include <algorithm>

bool for_string(std::string a, std::string b) {
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main() {
	int num;
	std::string strings[20001];

	std::scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		std::cin >> strings[i];
	}

	std::sort(strings, strings + num, for_string);
	for (int i = 0; i < num; i++) {
		if (i > 0 && strings[i] == strings[i - 1])
			continue;
		std::cout << strings[i] << std::endl;
	}
	return 0;
}