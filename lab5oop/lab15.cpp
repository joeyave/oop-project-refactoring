#include <iostream>
#include <string>

class Fraction
{
public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	void set_numerator(const int numerator)
	{
		numerator_ = numerator;
	}

	int get_numerator() const
	{
		return numerator_;
	}

	void set_denominator(const int denominator)
	{
		denominator_ = denominator;
	}

	int get_denominator() const
	{
		return denominator_;
	}

	float get_decimal() const
	{
		return static_cast<float>(numerator_) / static_cast<float>(denominator_);
	}

private:
	int numerator_;
	int denominator_;
};

struct NumDen
{
	int num;
	int den;
};

NumDen fraction_split(std::string& input)
{
	const unsigned int found = input.find('/');
	if (found != std::string::npos)
	{
		const std::string a = input.substr(0, found);
		const std::string b = input.substr(found + 1, input.length());
		const int num = stoi(a, nullptr, 10);
		const int den = stoi(b, nullptr, 10);

		return {num, den};
	}
	return {0, 0};
}

int main()
{
	std::string input;
	getline(std::cin, input);
	const NumDen num_den = fraction_split(input);

	Fraction fraction(num_den.num, num_den.den);
	std::cout << "Fraction in decimal is " << fraction.get_decimal() << std::endl;

	return 0;
}
