#include <iostream>
#include <stack>

using namespace std;

bool is_right(string str) {
	stack<char> s;

	for (int j = 0; j < static_cast<int>(str.length()); j++) {
		if (str[j] == '(') {
			s.push('(');
		} else {
			if (s.empty())
				return false;
			s.pop();
		}
	}

	return s.empty();
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	string str;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (is_right(str))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}