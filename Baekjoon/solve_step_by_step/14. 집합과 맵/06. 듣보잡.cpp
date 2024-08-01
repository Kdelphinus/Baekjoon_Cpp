#include <iostream>
#include <set>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, total = 0;
	string name, no_heared_seen = "";
	set<string> no_heared;
	set<string> no_seen;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name;
		no_heared.insert(name);
	}
	for (int i = 0; i < m; i++) {
		cin >> name;
		no_seen.insert(name);
	}

	for (auto &member : no_heared) {
		if (no_seen.find(member) != no_seen.end()) {
			total++;
			no_heared_seen += member + "\n";
		}
	}
	cout << total << "\n" << no_heared_seen;

	return 0;
}