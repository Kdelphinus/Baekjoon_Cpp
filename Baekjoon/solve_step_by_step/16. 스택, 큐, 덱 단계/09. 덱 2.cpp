#include <iostream>
#include <deque>

using namespace std;

int main() {
	int n, order, num;
	deque<int> d;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &order);
		if (order == 1) {
			scanf("%d", &num);
			d.push_front(num);
		} else if (order == 2) {
			scanf("%d", &num);
			d.push_back(num);
		} else if (order == 3) {
			if (d.empty())
				printf("-1\n");
			else {
				printf("%d\n", d.front());
				d.pop_front();
			}
		} else if (order == 4) {
			if (d.empty())
				printf("-1\n");
			else {
				printf("%d\n", d.back());
				d.pop_back();
			}
		} else if (order == 5) {
			printf("%ld\n", d.size());
		} else if (order == 6) {
			printf("%d\n", d.empty());
		} else if (order == 7) {
			if (d.empty())
				printf("-1\n");
			else
				printf("%d\n", d.front());
		} else if (order == 8) {
			if (d.empty())
				printf("-1\n");
			else
				printf("%d\n", d.back());
		}
	}
}