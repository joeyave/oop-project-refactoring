#include<iostream>
#include<string>

class StringValidator
{
public:
	virtual ~StringValidator() { }

	virtual bool is_valid(std::string input) = 0;
	virtual std::string get_validator_name() const = 0;
};

class PatternValidator final : public StringValidator
{
public:
	explicit PatternValidator(const std::string val)
	{
		val_ = val;
		name_ = "PatternValidator";
	}

	bool is_valid(std::string input) override;
	std::string get_validator_name() const override
	{
		return name_;
	}
private:
	std::string val_;
	std::string name_;
};

bool PatternValidator::is_valid(const std::string input)
{
	bool is_pattern = true;
	
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input.size() - i < val_.size())
		{
			break;
		}
		
		std::string temp = input.substr(i, val_.size());

		// Don't know how to refactor this.
		for (size_t j = 0; j < temp.size(); j++)
		{
			if (val_[j] == '?')
			{
				continue;
			}

			if (val_[j] == 'D')
			{
				if (isdigit(temp[j]))
				{
					continue;
				}
				is_pattern = false;
				break;
			}

			if (val_[j] == 'A')
			{
				if (isalpha(temp[j]))
				{
					continue;
				}
				is_pattern = false;
				break;
			}

			if (isalpha(val_[j]))
			{
				if (tolower(val_[j]) != tolower(temp[j]))
				{
					is_pattern = false;
					break;
				}
				continue;
			}

			if (val_[j] != temp[j])
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
	explicit MaxLengthValidator(const size_t num)
	{
		num_ = num;
		name_ = "MaxLengthValidator";
	}

	bool is_valid(std::string input) override;
	std::string get_validator_name() const override
	{
		return name_;
	}
private:
	size_t num_;
	std::string name_;
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
	explicit MinLengthValidator(const size_t num)
	{
		num_ = num;
		name_ = "MinLengthValidator";
	}

	bool is_valid(std::string input) override;
	std::string get_validator_name() const override
	{
		return name_;
	}
private:
	size_t num_;
	std::string name_;
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

void validate(StringValidator& validator, const std::string str1, const std::string str2)
{
	std::cout << validator.get_validator_name() << std::endl;
	print_valid(validator, str1);
	print_valid(validator, str2);
	std::cout << std::endl;
}

int main()
{
	MinLengthValidator min(6);
	MaxLengthValidator max(6);
	PatternValidator digit("D");

	validate(min, "hello", "wellcome");
	validate(max, "hello", "wellcome");
	validate(digit, "there are 2 types of sentences in the world",
		"valid and invalid ones");
	
	return 0;
}
