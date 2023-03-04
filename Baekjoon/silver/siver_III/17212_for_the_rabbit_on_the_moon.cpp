#include <iostream>

using namespace std;

int min_coin(int n)
{
	int dp[n + 1];

	for (int i = 0; i < n + 1; i++)
		dp[i] = INT32_MAX;
	dp[0] = 0;
	for (int i = 1; i < n + 1; i++)
	{
		if (i == 1 || i == 2 || i == 5 || i == 7)
			dp[i] = 1;
		else if (i < 5)
			dp[i] = min(dp[i - 1], dp[i - 2]) + 1;
		else if (i < 7)
			dp[i] = min(min(dp[i - 1], dp[i - 2]), dp[i - 5]) + 1;
		else
			dp[i] = min(min(min(dp[i - 1], dp[i - 2]), dp[i - 5]), dp[i - 7]) + 1;
	}
	return (dp[n]);
}

int main()
{
	int n;

	cin >> n;
	cout << min_coin(n);
}
