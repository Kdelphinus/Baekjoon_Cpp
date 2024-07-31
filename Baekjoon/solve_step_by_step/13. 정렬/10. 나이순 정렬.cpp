#include <iostream>
#include <algorithm>
#include <vector>

typedef std::pair<int, std::string> info;

bool for_info(info a, info b) {
	return a.first < b.first;
}

int main() {
	int n;
	info tmp;
	std::vector<info> users;

	std::scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		std::cin >> tmp.first >> tmp.second;
		users.push_back(tmp);
	}
	std::stable_sort(users.begin(), users.end(), for_info);
	for (int i = 0; i < n; i++) {
		std::cout << users[i].first << " " << users[i].second << "\n";
	}
	return 0;
}