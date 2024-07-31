#include <iostream>
#include <algorithm>

bool desc(char a, char b) {
	return a > b;
}

int main() {
	std::string str;

	std::cin >> str;
	std::sort(str.begin(), str.end(), desc);
	std::cout << str;

	return 0;
}