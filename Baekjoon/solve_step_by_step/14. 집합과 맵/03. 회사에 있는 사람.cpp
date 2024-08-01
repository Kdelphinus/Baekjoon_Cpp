#include <iostream>
#include <map>

using namespace std;

int main() {
	int n;
	string name, state;
	map<string, string, greater<string>> logs;
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> state;
		logs[name] = state;
	}

	for (auto &log : logs) {
		if (log.second == "enter")
			cout << log.first << "\n";
	}

	return 0;
}
