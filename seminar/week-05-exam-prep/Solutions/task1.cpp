#include <iostream>
using namespace std;

int main() {
	size_t number;
	cin >> number;

	for (size_t i = 0; i < number; i++)
	{
		bool is_row_even = i % 2 == 0;
		size_t number_to_display = is_row_even ? i * number + 1 : (i + 1) * number;
		for (size_t j = 0; j < number; j++)
		{
			cout << (is_row_even ? number_to_display++ : number_to_display--) << " ";
		}
		cout << endl;
	}

	return 0;
}
