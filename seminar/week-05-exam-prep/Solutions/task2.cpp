#include <iostream>
using namespace std;

int main() {
	const size_t INITIAL_ARRAY_MAX_SIZE = 128;
	int arr1[INITIAL_ARRAY_MAX_SIZE], arr2[INITIAL_ARRAY_MAX_SIZE], result[2 * INITIAL_ARRAY_MAX_SIZE];

	size_t size1, size2;
	cin >> size1;

	for (size_t i = 0; i < size1; i++)
	{
		cin >> arr1[i];
	}

	cin >> size2;

	for (size_t i = 0; i < size2; i++)
	{
		cin >> arr2[i];
	}

	size_t i = 0, j = 0, k = 0;
	while (i < size1 && j < size2)
	{
		if (arr1[i] <= arr2[j])
		{
			result[k++] = arr1[i++];
		}
		else
		{
			result[k++] = arr2[j++];
		}
	}

	while (i < size1)
	{
		result[k++] = arr1[i++];
	}

	while (j < size2)
	{
		result[k++] = arr2[j++];
	}

	for (size_t i = 0; i < k; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}
