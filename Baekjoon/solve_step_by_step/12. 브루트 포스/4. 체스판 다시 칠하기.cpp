#include <iostream>
#include <string>

int main() {
	int n, m, ans = 64;
	std::string board[51];

	std::scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		std::string tmp;
		std::cin >> tmp;
		board[i] = tmp;
	}

	for (int start_y = 0; start_y <= n - 8; start_y++) {
		for (int start_x = 0; start_x <= m - 8; start_x++) {
			int white = 0, black = 0;
			for (int i = start_y; i < start_y + 8; i++) {
				for (int j = start_x; j < start_x + 8; j++) {
					if ((i + j) % 2) {
						if (board[i][j] == 'W')
							white++;
						else
							black++;
					} else {
						if (board[i][j] == 'W')
							black++;
						else
							white++;
					}
				}
			}
			ans = std::min(std::min(white, black), ans);
			if (ans == 0) {
				std::printf("%d\n", ans);
				return 0;
			}
		}
	}
	std::printf("%d\n", ans);
	return 0;
}