#include <iostream>
#include <map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	std::map<int, std::string> idToName;
	std::map<std::string, int> nameToId;

	std::string name;
	for (int i = 0; i < N; i++) {
		std::cin >> name;
		idToName.insert(std::make_pair(i + 1, name));
		nameToId.insert(std::make_pair(name, i + 1));
	}

	for (int i = 0; i < M; i++) {
		std::cin >> name;
		if (std::isdigit(name[0]))
			std::cout << idToName[std::stoi(name)];
		else
			std::cout << nameToId[name];
		std::cout << "\n";
	}
}