#include <iostream>
#include <map>

using namespace std;

bool is_digit(const string &order) {
	for (unsigned long i = 0; i < order.length(); i++) {
		if (isdigit(order[i]) == 0)
			return false;
	}
	return true;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	string name, order;
	map<string, int> name_to_id;
	map<int, string> id_to_name;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> name;
		name_to_id[name] = i;
		id_to_name[i] = name;
	}

	for (int i = 0; i < m; i++) {
		cin >> order;
		if (is_digit(order) == true)
			cout << id_to_name[stoi(order)] << "\n";
		else
			cout << name_to_id[order] << "\n";
	}

	return 0;
}