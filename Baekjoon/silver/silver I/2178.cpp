#include <iostream>
#include <queue>

int N, M;
int DIRECTIONS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
std::string MAZE[101];

int bfs() {
	int y, x, ny, nx, cnt;
	std::pair<int, std::pair<int, int>> coor;
	std::queue < std::pair < int, std::pair < int, int>>> que;
	que.push(std::make_pair(1, std::make_pair(0, 0)));
	MAZE[0][0] = '0';

	while (!que.empty()) {
		coor = que.front();
		que.pop();
		y = coor.second.first;
		x = coor.second.second;
		cnt = coor.first;
		if (y == N - 1 && x == M - 1)
			return cnt;
		for (int i = 0; i < 4; i++) {
			ny = y + DIRECTIONS[i][0];
			nx = x + DIRECTIONS[i][1];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && MAZE[ny][nx] == '1') {
				que.push(std::make_pair(cnt + 1, std::make_pair(ny, nx)));
				MAZE[ny][nx] = '0';
			}
		}
	}
	return -1;
}

int main() {
	std::cin.tie(NULL);

	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
		std::cin >> MAZE[i];
	std::cout << bfs();
}