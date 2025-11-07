#include <iostream>
using namespace std;

int main() {
	size_t a, b;
	cin >> a >> b;

	size_t count = 0;

	for (size_t i = a; i <= b; i++)
	{
		size_t sum = 0;
		size_t number = i;
		while (i > 0)
		{
			sum += number % 10;
			number /= 10;
		}

		bool is_funny = true;
		size_t last_digit = sum % 10;
		sum /= 10;
		while (sum > 0 && is_funny)
		{
			size_t digit = sum % 10;
			sum /= 10;

			
			is_funny = digit % 2 == last_digit % 2;
			last_digit = digit;
		}

		count += is_funny;
	}

	return 0;
}
