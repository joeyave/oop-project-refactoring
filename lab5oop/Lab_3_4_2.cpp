#include <iostream>

bool is_leap(const int year)
{
	if (year % 4 == 0 and year % 100 != 0 or year % 400 == 0)
	{
		return true;
	}
	return false;
}

int month_length(const int year, const int month)
{
	int lengths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && is_leap(year))
	{
		return 29;
	}
	return *(lengths + (month - 1));
}

int main()
{
	for (int yr = 2000; yr < 2002; yr++)
	{
		for (int mo = 1; mo <= 12; mo++)
			std::cout << month_length(yr, mo) << " ";
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}
