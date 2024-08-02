#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int n, order, number;
	stack<int> s;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &order);
		if (order == 1) {
			scanf("%d", &number);
			s.push(number);
		} else if (order == 2) {
			if (s.empty())
				printf("-1\n");
			else {
				printf("%d\n", s.top());
				s.pop();
			}
		} else if (order == 3) {
			printf("%lu\n", s.size());
		} else if (order == 4) {
			printf("%d\n", s.empty());
		} else if (order == 5) {
			if (s.empty())
				printf("-1\n");
			else
				printf("%d\n", s.top());
		} else {
			printf("Wrong Order.\n");
		}
	}

	return 0;
}