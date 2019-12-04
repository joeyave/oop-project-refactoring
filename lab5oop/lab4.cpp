#include <iostream>

void year_check(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		std::cout << "Leap year.\n";
	}
	else
	{
		std::cout << "Common year.\n";
	}
}

int main()
{
	std::cout << "2000 == Expected value == Leap year => Function Value == ";
	year_check(2000);
	std::cout << "2015 == Expected value == Common year => Function Value == ";
	year_check(2015);
	std::cout << "1999 == Expected value == Common year => Function Value == ";
	year_check(1999);
	std::cout << "1996 == Expected value == Leap year => Function Value == ";
	year_check(1996);
	std::cout << "1900 == Expected value == Common year => Function Value == ";
	year_check(1900);

	return 0;
}
