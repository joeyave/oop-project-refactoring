#include <iostream>

int main()
{
	int value;
	std::cout << "N: ";
	std::cin >> value;
	std::cout << "Result: " << value * (value + 1) / 2;

	return 0;
}
