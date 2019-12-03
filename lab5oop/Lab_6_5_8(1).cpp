#include <iostream>
#include <string>

class IPAdress
{
public:
	explicit IPAdress(const std::string& value) : value_(value) { }

	IPAdress(const IPAdress& other)
	{
		value_ = other.value_;
	}

	IPAdress() { }

	~IPAdress()
	{
		value_ = "";
	}

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
	}

	IPAs()
	{
		items_ = new IPAdress[10000];
	}

	void add_to_array(IPAdress ip_adress);

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
	int n_ = 0;
	int iter_ = 0;
};

void IPAs::add_to_array(const IPAdress ip_adress)
{
	items_[iter_] = ip_adress;
	iter_++;
}

int main()
{
	std::string str;
	
	std::cout << "Enter text: " << std::endl;
	
	IPAs* ipa1 = new IPAs();
	IPAs* ipa2 = new IPAs();
	
	for (int i = 0; i < 5; i++)
	{
		getline(std::cin, str);
		IPAdress* ip_adress = new IPAdress(str);
		
		if (i < 2)
		{
			ipa1->add_to_array(*ip_adress);
		}
		else if (i == 2)
		{
			ipa1->add_to_array(*ip_adress);
			ipa2->add_to_array(*ip_adress);
		}
		else
		{
			ipa2->add_to_array(*ip_adress);
		}
	}

	ipa1->show(1);
	ipa2->show(2);
	
	return 0;
}
