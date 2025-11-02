#include <iostream>

const unsigned int SIZE = 1028;

int main() {
	unsigned int n, element;
	int arr[SIZE];

	std::cin >> n;
	for (unsigned int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	std::cin >> element;

	for (unsigned int i = 0; i < n; i++)
	{
		unsigned int index = i;
		for (unsigned int j = i + 1; j < n; j++)
		{
			if (arr[index] > arr[j]) {
				index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}


	for (unsigned int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}

	// Binary search
	int result = -1;
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int middle = (left + right) / 2;

		if (arr[middle] == element) { 
			result = middle;
			break;
		}

		if (arr[middle] < element) {
			left = middle + 1;
		}

		else {
			right = middle;
		}
	}


	std::cout << result;
	return 0;
}
