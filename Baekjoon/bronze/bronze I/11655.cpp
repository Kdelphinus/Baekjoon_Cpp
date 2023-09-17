#include <iostream>

std::string UPPER_ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string LOWER_ALPHABET = "abcdefghijklmnopqrstuvwxyz";

void upperPrint(char c) {
	int idx = UPPER_ALPHABET.find(c) + 13;

	if (idx > 25)
		idx -= 26;
	std::cout << UPPER_ALPHABET[idx];
}

void lowerPrint(char c) {
	int idx = LOWER_ALPHABET.find(c) + 13;

	if (idx > 25)
		idx -= 26;
	std::cout << LOWER_ALPHABET[idx];
}

int main() {
	std::string str;
	std::getline(std::cin, str);

	for (int i = 0; i < str.size(); i++) {
		if (std::isupper(str[i]))
			upperPrint(str[i]);
		else if (std::islower(str[i]))
			lowerPrint(str[i]);
		else
			std::cout << str[i];
	}
	std::cout << std::endl;
	return 0;
}