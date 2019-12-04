#include <iostream>
#include <string>

class ShopItemOrder
{
public:
	ShopItemOrder(const std::string name, const float unit_price, const int amount_ordered)
	{
		unit_name_ = name;
		unit_price_ = unit_price;
		amount_ordered_ = amount_ordered;
	}

	std::string get_unit_name() const
	{
		return unit_name_;
	}

	float get_unit_price() const
	{
		return unit_price_;
	}

	int get_number_ordered() const
	{
		return amount_ordered_;
	}

	float get_total_price() const
	{
		return static_cast<float>(amount_ordered_) * unit_price_;
	}

	void print() const
	{
		std::cout << "Ordered: " << unit_name_ << std::endl
			<< "Amount: " << amount_ordered_ << std::endl
			<< "Price: " << unit_price_ << std::endl;

		std::cout << "Total price is " << get_total_price() << std::endl;
	}

private:
	std::string unit_name_;
	float unit_price_;
	int amount_ordered_;
};

int main()
{
	ShopItemOrder order("MacBook", 2000.0, 2);
	order.print();

	return 0;
}
