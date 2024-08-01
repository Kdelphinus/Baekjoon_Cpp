#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, tmp, total = 0;
	int A[200001], B[200001];
	map<int, int> A_map, B_map;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		A[i] = tmp;
		A_map[tmp]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		B[i] = tmp;
		B_map[tmp]++;
	}

	for (int i = 0; i < n; i++) {
		if (B_map[A[i]] == 0)
			total++;
	}
	for (int i = 0; i < m; i++) {
		if (A_map[B[i]] == 0)
			total++;
	}
	cout << total << "\n";

	return 0;
}