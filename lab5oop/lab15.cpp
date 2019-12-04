#include <iostream>
#include <string>

class Fraction
{
public:
	Fraction(int numerator, int denominator);
	double to_double() const;
	std::string to_string() const;
private:
	int numerator_;
	int denominator_;
};

Fraction::Fraction(const int numerator, const int denominator)
{
	numerator_ = numerator;
	denominator_ = denominator;
}

double Fraction::to_double() const
{
	return static_cast<double>(numerator_) / denominator_;
}

std::string Fraction::to_string() const
{
	std::string data;

	int num = numerator_;
	const int denum = denominator_;
	const int whole = num / denum;
	const int remain = whole * denum;

	num -= remain;
	std::string input = std::to_string(whole);
	data += input;
	data += " ";
	input = std::to_string(num);
	data += input;
	data += "/";
	input = std::to_string(denum);
	data += input;

	return data;
}

int main()
{
	int num = 0;
	int den = 0;

	std::string input = "";
	getline(std::cin, input);

	if (input.find("/") != -1)
	{
		const int x = input.find("/");
		const std::string a = input.substr(0, x);
		const std::string b = input.substr(x + 1, input.length());
		num = stoi(a, nullptr, 10);
		den = stoi(b, nullptr, 10);
	}

	const Fraction fraction(num, den);
	std::cout << fraction.to_string() << " is "
		<< fraction.to_double() << " in decimal" << std::endl;

	return 0;
}
