#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	int n, m, total = 0;
	string word;
	unordered_map<string, int> dictionary;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		cin >> word;
		dictionary[word] = 1;
	}

	for (int i = 0; i < m; i++) {
		cin >> word;
		if (dictionary.find(word) != dictionary.end())
			total++;
	}

	cout << total << "\n";

	return 0;
}