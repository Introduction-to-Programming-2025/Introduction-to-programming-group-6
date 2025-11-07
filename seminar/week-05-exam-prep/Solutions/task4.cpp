#include <iostream>
using namespace std;

int main() {
	const size_t MAX_SIZE = 1024;
	int array[MAX_SIZE];
	size_t size;

	std::cin >> size;
	for (size_t i = 0; i < size; ++i) {
		std::cin >> array[i];
	}

	size_t k = size;
	bool is_k_valid = true;

	do {
		k--;
		is_k_valid = true;
		for (size_t i = k; i < size; ++i) {
			int difference = array[i] - array[i - k];
			difference = difference >= 0 ? difference : -difference;
			if (difference != k)
			{
				is_k_valid = false;
				break;
			}
		}
	} while (k > 0 && !is_k_valid);

	if (k > 0) {
		std::cout << k << std::endl;
	}
	else {
		std::cout << "No solution" << std::endl;
	}

	return 0;
}
