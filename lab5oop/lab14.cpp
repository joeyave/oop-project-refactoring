#include <iostream>
#include <string>

using namespace std;


class ShopItemOrder
{
public:
	ShopItemOrder(const string name, const double unit_price, const int number_ordered)
	{
		unit_name_ = name;
		unit_price_ = unit_price;
		number_ordered_ = number_ordered;
	}

	string name_item() const
	{
		return unit_name_;
	}

	float price_item() const
	{
		return unit_price_;
	}

	int number_item() const
	{
		return number_ordered_;
	}

	double get_total_price() const
	{
		return unit_price_ * number_ordered_;
	}

	void print() const
	{
		cout << "Ordered: " << unit_name_ << endl << "Number: " << number_ordered_ << endl
			<< "Price: " << unit_price_ << endl;
	}

private:
	string unit_name_;
	float unit_price_;
	int number_ordered_;
};

int main()
{
	ShopItemOrder order("MacBook", 2000.0, 2);

	order.print();
	cout << "===========" << endl;
	cout << "Total price: " << order.get_total_price() << endl;

	return 0;
}
