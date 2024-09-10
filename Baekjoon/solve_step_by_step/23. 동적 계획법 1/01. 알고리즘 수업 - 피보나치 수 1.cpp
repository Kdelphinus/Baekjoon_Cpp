#include <iostream>

using namespace std;

int main() {
	int n, x;

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	int dp[2] = {1, 1};
	for (int i = 0; i < n - 2; i++) {
		x = dp[0] + dp[1];
		dp[0] = dp[1];
		dp[1] = x;
	}
	cout << dp[1] << " " << n - 2 << "\n";
	
	return 0;
}