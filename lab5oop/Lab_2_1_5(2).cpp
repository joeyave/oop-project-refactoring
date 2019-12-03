#include <iostream>

void tax_calculate(const float grossprice, const float taxrate)
{
	std::cout << "grossprice = " << grossprice << " taxrate = " << taxrate << std::endl;

	float netprice = 0.0f;
	float taxvalue = 0.0f;

	if (grossprice > 0)
	{
		if (taxrate > 0 && taxrate <= 100)
		{
			netprice = grossprice / (1 + taxrate / 100);
			taxvalue = netprice * (taxrate / 100);
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
