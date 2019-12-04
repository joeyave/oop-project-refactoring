#include <iostream>

int main()
{
	int a = 0, b = 0, c = 0;

	std::cin >> b;
	std::cin >> a;

	try
	{
		if (b == 0 and a == 0)
		{
			throw std::exception("There is no need for expression.\n");
		}

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
