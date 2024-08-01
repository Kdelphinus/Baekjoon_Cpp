#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, tmp;
	unordered_map<int, int> cards;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		cards[tmp]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		cout << cards[tmp] << " ";
	}
	cout << "\n";

	return 0;
}