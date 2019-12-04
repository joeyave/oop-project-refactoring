#include <iostream>

const int MONTHS_NUM = 12;
const int DAYS_NUM = 29;

const int YEAR_ITERATOR_BEGIN = 2000;
const int YEAR_ITERATOR_END = 2002;
const int MONTH_ITERATOR_BEGIN = 1;
const int MONTH_ITERATOR_END = 12;

bool is_leap(const int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return true;
	}
	return false;
}

int month_length(const int year, const int month)
{
	int lengths[MONTHS_NUM] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 2 && is_leap(year))
	{
		return DAYS_NUM;
	}
	return *(lengths + (month - 1));
}

int main()
{
	for (int yr = YEAR_ITERATOR_BEGIN; yr < YEAR_ITERATOR_END; yr++)
	{
		for (int mo = MONTH_ITERATOR_BEGIN; mo <= MONTH_ITERATOR_END; mo++)
		{
			std::cout << month_length(yr, mo) << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
