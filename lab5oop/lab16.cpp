#include<iostream>
#include<string>

class StringValidator
{
public:
	virtual ~StringValidator() { }

	virtual bool is_valid(std::string input) = 0;
};

class ExactValidator final : public StringValidator
{
public:
	explicit ExactValidator(const std::string input) { password_ = input; }
	bool is_valid(std::string input) override;
private:
	std::string password_;
};

bool ExactValidator::is_valid(const std::string input)
{
	std::cout << input << std::endl;
	if (input.compare(password_) == 0)
	{
		return true;
	}
	return false;
}

class DummyValidator final : public StringValidator
{
public:
	bool is_valid(std::string input) override;
};

bool DummyValidator::is_valid(std::string input)
{
	return true;
}

void print_valid(StringValidator& validator, const std::string input)
{
	std::cout << "The string '" << input << "' is "
		<< (validator.is_valid(input) ? "valid" : "invalid");
}

int main()
{
	DummyValidator dummy;
	print_valid(dummy, "hello");
	std::cout << std::endl;

	ExactValidator exact("secret");
	print_valid(exact, "hello");
	std::cout << std::endl;

	print_valid(exact, "secret");
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}
