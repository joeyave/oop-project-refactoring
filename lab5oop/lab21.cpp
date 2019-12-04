#include <string>
#include <iostream>


class NegativeException
{
public:
	explicit NegativeException(const std::string& msg) : msg_(msg) {}
	std::string get_message() const { return msg_; }
private:
	std::string msg_;
};


float square_area(const float a)
{
	float c = 0;
	try
	{
		if (a <= 0)
		{
			throw NegativeException("Your input is not valid. The area can't be negative.");
		}

		c = a * a;
	}
	catch (NegativeException & e)
	{
		std::cout << e.get_message() << "\n";
	}

	return c;
}

float rectangle_area(const float a, const float b)
{
	float c = 0;

	try
	{
		if (a > 0 and b > 0)
		{
			c = a * b;
		}
		else
		{
			throw NegativeException("Your input is not valid. The area can't be negative.");
		}
	}
	catch (NegativeException & e)
	{
		std::cout << e.get_message() << "\n";
	}

	return c;
}


int main()
{
	float a, b;
	std::cin >> a;
	std::cin >> b;

	const float rsquare = square_area(a);
	const float rrectangle = rectangle_area(a, b);
	std::cout << rsquare << std::endl << rrectangle << std::endl;

	return 0;
}

