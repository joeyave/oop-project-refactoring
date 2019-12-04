#include <iostream>

int main()
{
	const int a_var = 8;
	int b_var = 0;
	int c_var = 0;

	std::cout << "Value b: ";
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
