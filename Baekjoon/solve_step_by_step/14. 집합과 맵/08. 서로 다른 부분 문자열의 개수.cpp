#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string word;
	unordered_set<string> sub_words;

	cin >> word;
	for (unsigned long i = 1; i < word.length(); i++) {
		for (unsigned long j = 0; j + i <= word.length(); j++) {
			sub_words.insert(word.substr(j, i));
		}
	}
	cout << sub_words.size() + 1 << "\n"; // �ڱ� �ڽ� ����

	return 0;
}