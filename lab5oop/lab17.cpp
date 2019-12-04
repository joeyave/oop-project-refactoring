#include<iostream>
#include<string>

class StringValidator
{
public:
	virtual ~StringValidator() { }

	virtual bool is_valid(std::string input) = 0;
};

class PatternValidator final : public StringValidator
{
public:
	explicit PatternValidator(const std::string val) : val_(val) { }

	bool is_valid(std::string input) override;
private:
	std::string val_;
};

bool PatternValidator::is_valid(const std::string input)
{
	std::string tmpStr;
	bool is_pattern = true;
	for (int i = 0; i < input.size(); i++)
	{
		if (input.size() - i < val_.size())
		{
			break;
		}
		tmpStr = input.substr(i, val_.size());
		for (int j = 0; j < tmpStr.size(); j++)
		{
			if (val_[j] == '?')
			{
				continue;
			}

			if (val_[j] == 'D')
			{
				if (isdigit(tmpStr[j]))
				{
					continue;
				}
				is_pattern = false;
				break;
			}

			if (val_[j] == 'A')
			{
				if (isalpha(tmpStr[j]))
				{
					continue;
				}
				is_pattern = false;
				break;
			}

			if (isalpha(val_[j]))
			{
				if (tolower(val_[j]) != tolower(tmpStr[j]))
				{
					is_pattern = false;
					break;
				}
				continue;
			}

			if (val_[j] != tmpStr[j])
			{
				is_pattern = false;
				break;
			}
		}

		if (is_pattern)
		{
			return is_pattern;
		}
		is_pattern = true;
	}
	return !is_pattern;
}

class MaxLengthValidator final : public StringValidator
{
public:
	explicit MaxLengthValidator(const int num) : num_(num)
	{
	}

	bool is_valid(std::string input) override;
private:
	int num_;
};

bool MaxLengthValidator::is_valid(const std::string input)
{
	if (input.length() > num_)
	{
		return false;
	}
	return true;
}

class MinLengthValidator final : public StringValidator
{
public:
	explicit MinLengthValidator(const int num) : num_(num)
	{
	}

	bool is_valid(std::string input) override;
private:
	int num_;
};


bool MinLengthValidator::is_valid(const std::string input)
{
	if (input.length() < num_)
	{
		return false;
	}
	return true;
}

void print_valid(StringValidator& validator, const std::string input)
{
	std::cout << "The string '" << input << "' is "
		<< (validator.is_valid(input) ? "valid" : "invalid") << std::endl;
}

int main()
{
	std::cout << "MinLengthValidator" << std::endl;
	MinLengthValidator min(6);
	print_valid(min, "hello");
	print_valid(min, "welcome");
	std::cout << std::endl;
	std::cout << "MaxLengthValidator" << std::endl;
	MaxLengthValidator max(6);
	print_valid(max, "hello");
	print_valid(max, "welcome");
	std::cout << std::endl;
	std::cout << "PatternValidator" << std::endl;
	PatternValidator digit("D");
	print_valid(digit, "there are 2 types of sentences in the world");
	print_valid(digit, "valid and invalid ones");
	std::cout << std::endl;
	system("pause");
	return 0;
}
