#include <iostream>
#include <algorithm>
#include <vector>

typedef std::pair<int, int> coor;

bool for_coor(coor a, coor b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int num;
	coor tmp;
	coor coordinate[100001];

	std::scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		std::scanf("%d %d", &tmp.first, &tmp.second);
		coordinate[i] = tmp;
	}
	std::sort(coordinate, coordinate + num, for_coor);

	for (int i = 0; i < num; i++) {
		std::printf("%d %d\n", coordinate[i].first, coordinate[i].second);
	}

	return 0;
}