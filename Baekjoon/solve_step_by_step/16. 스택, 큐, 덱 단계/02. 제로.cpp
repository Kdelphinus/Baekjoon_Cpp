#include <iostream>
#include <stack>

using namespace std;

int main() {
	int k, n, total = 0;
	stack<int> s;

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		if (n)
			s.push(n);
		else
			s.pop();
	}
	while (!s.empty()) {
		total += s.top();
		s.pop();
	}
	printf("%d\n", total);

	return 0;
}