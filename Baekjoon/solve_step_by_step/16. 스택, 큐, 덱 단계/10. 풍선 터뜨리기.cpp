#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, int> ballon;


int main() {
	int n;
	bool right;
	ballon tmp, move;
	deque<ballon> d;

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp.second;
		tmp.first = i;
		d.push_back(tmp);
	}

	while (!d.empty()) {
		move = d.front();
		d.pop_front();
		cout << move.first << " ";
		if (move.second > 0)
			right = true;
		else {
			right = false;
			move.second *= -1;
		}
		for (int i = 0; i < move.second; i++) {
			if (right) {
				if (i == move.second - 1)
					continue;
				d.push_back(d.front());
				d.pop_front();
			} else {
				d.push_front(d.back());
				d.pop_back();
			}
		}
	}

	return 0;
}