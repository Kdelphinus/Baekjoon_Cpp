#include <iostream>
#include <map>

int main() {
	std::map<char, int> alphabets;
	std::string str;
	std::string alpha = "abcdefghijklmnopqrstuvwxyz";

	std::cin >> str;
	for (int i = 0; i < str.size(); i++)
		alphabets[str[i]]++;

	for (int i = 0; i < alpha.size(); i++)
		std::cout << alphabets[alpha[i]] << " ";

	return 0;
}