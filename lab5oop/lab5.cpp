#include <iostream>

void tax_calculate(const float grossprice, const float taxrate)
{
	std::cout << "grossprice = " << grossprice
		<< " taxrate = " << taxrate << std::endl;

	float netprice = 0.0f;
	float taxvalue = 0.0f;

	const int MIN_TEXTRATE = 0;
	const int MAX_TEXTRATE = 100;

	if (grossprice > MIN_TEXTRATE)
	{
		if (taxrate > MIN_TEXTRATE&& taxrate <= MAX_TEXTRATE)
		{
			netprice = grossprice / (1 + taxrate / MAX_TEXTRATE);
			taxvalue = netprice * (taxrate / MAX_TEXTRATE);
		}
	}

	std::cout << "Net price: " << netprice << std::endl;
	std::cout << "Tax value: " << taxvalue << std::endl;
	std::cout << std::endl;
}

int main()
{
	tax_calculate(123, 23);
	tax_calculate(123, 50);
	tax_calculate(123, 98);
	tax_calculate(11, 10);

	return 0;
}
