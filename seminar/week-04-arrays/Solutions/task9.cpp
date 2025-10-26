#include <iostream>

const unsigned int SIZE = 1028;

int main() {
	unsigned int n, m;
	float arr[SIZE];

	std::cin >> n >> m;

	for (unsigned int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	for (unsigned int i = 0; i < n; i++) {
		unsigned int index = i;
		for (unsigned int j = i + 1; j < n; j++) {
			if (arr[index] > arr[j]) {
				index = j;
			}
		}
		float temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}

	float min_sum = 0;
	float max_sum = 0;

	for (unsigned int i = 0; i < m; i++)
	{
		min_sum += arr[i];
		max_sum += arr[n - m + i];
	}

	std::cout << min_sum << std::endl;
	std::cout << max_sum << std::endl;
	return 0;
}
