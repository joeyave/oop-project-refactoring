#include <iostream>
#include <string>

const int MAX_ITEMS = 10000;

class IPAdress
{
public:
	explicit IPAdress(const std::string& value)
	{
		value_ = value;
	}

	IPAdress(const IPAdress& other)
	{
		value_ = other.value_;
	}

	IPAdress() { }

	void print() const
	{
		std::cout << value_ << std::endl;
	}
	
protected:
	std::string value_;
};

class IPAs
{
public:
	explicit IPAs(const int n)
	{
		items_ = new IPAdress[n];
		iter_ = 0;
	}

	IPAs()
	{
		items_ = new IPAdress[MAX_ITEMS];
		iter_ = 0;
	}

	void add_to_array(IPAdress ip_address);

	void show(const int n) const
	{
		std::cout << "Network " << n << std::endl;
		for (int i = 0; i < iter_; i++)
		{
			items_[i].print();
		}
	}
private:
	IPAdress* items_;
	int iter_;
};

void IPAs::add_to_array(const IPAdress ip_address)
{
	items_[iter_] = ip_address;
	iter_++;
}

int main()
{
	std::string str;

	IPAs* ipa1 = new IPAs();
	IPAs* ipa2 = new IPAs();

	std::cout << "Enter text: " << std::endl;

	const int INPUT_NUM = 5;
	for (int i = 0; i < INPUT_NUM; i++)
	{
		getline(std::cin, str);
		IPAdress* ip_address = new IPAdress(str);

		if (i < 2)
		{
			ipa1->add_to_array(*ip_address);
		}
		else if (i == 2)
		{
			ipa1->add_to_array(*ip_address);
			ipa2->add_to_array(*ip_address);
		}
		else
		{
			ipa2->add_to_array(*ip_address);
		}

		delete ip_address;
	}

	ipa1->show(1);
	ipa2->show(2);

	delete ipa1;
	delete ipa2;
	return 0;
}
