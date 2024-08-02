#include <iostream>
#include <stack>

using namespace std;

string is_possible(int n) {
	int num, order = 1;
	stack<int> s;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (order == num) {
			order++;
		} else {
			while (!s.empty() && order == s.top()) {
				order++;
				s.pop();
			}
			if (!s.empty() && s.top() < num) {
				return "Sad";
			}
			s.push(num);
		}
	}

	while (!s.empty()) {
		if (s.top() == order) {
			s.pop();
			order++;
		} else {
			return "Sad";
		}
	}
	return "Nice";
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << is_possible(n) << "\n";
	return 0;
}