#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, num;
	string order;
	queue<int> q;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> order;
		if (order == "push") {
			cin >> num;
			q.push(num);
		} else if (order == "pop") {
			if (q.empty()) {
				cout << -1 << "\n";
			} else {
				cout << q.front() << "\n";
				q.pop();
			}
		} else if (order == "size") {
			cout << q.size() << "\n";
		} else if (order == "empty") {
			cout << q.empty() << "\n";
		} else if (order == "front") {
			if (q.empty()) {
				cout << -1 << "\n";
			} else {
				cout << q.front() << "\n";
			}
		} else if (order == "back") {
			if (q.empty()) {
				cout << -1 << "\n";
			} else {
				cout << q.back() << "\n";
			}
		} else {
			cout << "Wrong order.\n";
		}
	}

	return 0;
}