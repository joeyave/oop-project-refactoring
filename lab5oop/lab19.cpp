#include <iostream>

int main()
{
	const int a = 8;
	int b = 0;
	int c = 0;

	std::cout << "Value b: ";
	std::cin >> b;

	try
	{
		if (b == 0)
		{
			throw std::exception("Your input is not valid, you can't divide by zero.\n");
		}
		c = a / b;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}

	std::cout << c << std::endl;

	return 0;
}
