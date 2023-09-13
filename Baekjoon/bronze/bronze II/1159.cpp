#include <iostream>
#include <map>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;

	std::string name;
	std::string ans;
	std::map<char, int> player;
	for (int i = 0; i < n; i++) {
		std::cin >> name;
		player[name[0]]++;
		if (player[name[0]] == 5)
			ans += name[0];
	}
	if (ans.empty()) {
		std::cout << "PREDAJA" << std::endl;
		return 0;
	}
	std::sort(ans.begin(), ans.end());
	std::cout << ans << std::endl;
	return 0;
}