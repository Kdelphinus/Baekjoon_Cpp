#include <iostream>

using namespace std;

int dp[21][21][21];

int print_w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return print_w(20, 20, 20);
	else if (dp[a][b][c])
		return dp[a][b][c];
	else if (a < b && b < c) {
		dp[a][b][c] = print_w(a, b, c - 1) + print_w(a, b - 1, c - 1) - print_w(a, b - 1, c);
		return dp[a][b][c];
	}
	dp[a][b][c] =
			print_w(a - 1, b, c) + print_w(a - 1, b - 1, c) + print_w(a - 1, b, c - 1) - print_w(a - 1, b - 1, c - 1);
	return dp[a][b][c];
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if ((a == -1) && (b == -1) && (c == -1))
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << print_w(a, b, c) << "\n";
	}
	return 0;
}