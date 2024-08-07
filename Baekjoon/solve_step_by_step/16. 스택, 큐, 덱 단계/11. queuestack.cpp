#include <iostream>

using namespace std;

void cal_queuestack(int n, const int *queuestack, int m, const int *input_element, int *is_stack) {
	int v[100001] = {0,}, size = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (is_stack[i] == 0) {
			v[size] = queuestack[i];
			size++;
			if (size == m) {
				for (int j = 0; j < m; j++)
					cout << v[j] << " ";
				cout << "\n";
				return;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		v[size] = input_element[i];
		size++;
		if (size == m) {
			for (int j = 0; j < m; j++)
				cout << v[j] << " ";
			cout << "\n";
			return;
		}
	}
}

int main() {
	int n, m;

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	int is_stack[n], queuestack[n];
	for (int i = 0; i < n; i++)
		cin >> is_stack[i];
	for (int i = 0; i < n; i++)
		cin >> queuestack[i];
	cin >> m;
	int input_element[m];
	for (int i = 0; i < m; i++)
		cin >> input_element[i];

	cal_queuestack(n, queuestack, m, input_element, is_stack);

	return 0;
}