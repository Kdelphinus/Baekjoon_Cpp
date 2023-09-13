#include <iostream>

int isPalindrome(std::string str) {
	int len = str.size();
	for (int i = 0; i < str.size() / 2; i++)
		if (str[i] != str[len - i - 1])
			return 0;
	return 1;
}

int main() {
	std::string str;
	std::cin >> str;
	std::cout << isPalindrome(str) << std::endl;
}