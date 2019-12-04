#include <string>
#include <iostream>


class NegativeException : std::exception
{
public:
	explicit NegativeException(const std::string& msg)
	{
		error_message_ = msg;
	}

	const char* what() const noexcept override
	{
		return error_message_.c_str();
	}

private:
	std::string error_message_;
};


float square_area(const float latitude)
{
	float area = 0;
	try
	{
		if (latitude <= 0)
		{
			throw NegativeException("Your input is not valid. The area can't be negative.");
		}

		area = latitude * latitude;
	}
	catch (NegativeException& e)
	{
		std::cout << e.what() << "\n";
	}

	return area;
}

float rectangle_area(const float latitude, const float longitude)
{
	float area = 0;

	try
	{
		if (latitude > 0 and longitude > 0)
		{
			area = latitude * longitude;
		}
		else
		{
			throw NegativeException("Your input is not valid. The area can't be negative.");
		}
	}
	catch (NegativeException& e)
	{
		std::cout << e.what() << "\n";
	}

	return area;
}


int main()
{
	float latitude, longitude;
	std::cout << "Input latitude: ";
	std::cin >> latitude;
	std::cout << "Input longitude: ";
	std::cin >> longitude;

	const float square = square_area(latitude);
	const float rectangle = rectangle_area(latitude, longitude);
	std::cout << "Square area is " << square << std::endl;
	std::cout << "Rectangle area is " << rectangle << std::endl;

	return 0;
}
