#include <iostream>
#include <stack>

using namespace std;

string is_balance(string &str) {
	stack<char> s;

	for (unsigned long i = 0; i < str.length(); i++) {
		cout << str[i] << "\n";
		if (str[i] == '(') {
			s.push('(');
		} else if (str[i] == '[') {
			s.push('[');
		} else if (str[i] == ')') {
			if (!s.empty() && s.top() == '(') {
				s.pop();
			} else {
				return "no\n";
			}
		} else if (str[i] == ']') {
			if (!s.empty() && s.top() == '[') {
				s.pop();
			} else {
				return "no\n";
			}
		}
	}

	if (s.empty())
		return "yes\n";
	return "no\n";
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	while (true) {
		string str;
		getline(cin, str);
		if (str == ".")
			break;
		cout << is_balance(str);
	}
	return 0;
}