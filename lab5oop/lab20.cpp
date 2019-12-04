#include <iostream>

int main()
{
	int a_var = 0, b_var = 0, c_var = 0;

	std::cout << "Input a: ";
	std::cin >> a_var;

	std::cout << "Input b: ";
	std::cin >> b_var;

	try
	{
		if (b_var == 0)
		{
			throw std::exception("Your input is not valid, you can't divide by zero.\n");
		}

		c_var = a_var / b_var;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}

	std::cout << c_var << std::endl;

	return 0;
}
