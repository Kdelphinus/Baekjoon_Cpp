#include <iostream>
#include <queue>

using namespace std;

int bfs(int n, int start, int graph[102][102]) {
	int cnt = 0;
	int visited[102] = {};
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (current != i && graph[current][i] == 1 && visited[i] == 0) {
				cnt++;
				q.push(i);
				visited[i] = 1;
			}
		}
	}

	return cnt;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, pair;
	int com1, com2;
	cin >> n >> pair;

	int graph[102][102] = {};
	for (int i = 0; i < pair; i++) {
		cin >> com1 >> com2;
		graph[com1][com2] = 1;
		graph[com2][com1] = 1;
	}
	cout << bfs(n, 1, graph) << "\n";

	return 0;
}