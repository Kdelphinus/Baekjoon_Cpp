#include <iostream>
#include <vector>

int main() {
	std::vector<int> price(4);
	std::cin >> price[1] >> price[2] >> price[3];

	int start, end;
	std::vector<int> arr(101);
	for (int i = 0; i < 3; i++) {
		std::cin >> start >> end;
		for (int j = start; j < end; j++)
			arr[j]++;
	}

	int ans = 0;
	for (int i = 0; i < arr.size(); i++)
		ans += price[arr[i]] * arr[i];
	std::cout << ans << std::endl;

	return 0;
}