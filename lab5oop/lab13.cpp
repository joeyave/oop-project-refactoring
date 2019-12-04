#include<iostream>
#include<string>

class Person
{
public:
	Person(const std::string name, const std::string eye_color, const std::string favourite_series, const int age)
	{
		name_ = name;
		eye_color_ = eye_color;
		favourite_series_ = favourite_series;
		age_ = age;
	}

	std::string get_name() const
	{
		return name_;
	}

	void set_name(const std::string name)
	{
		name_ = name;
	}

	std::string get_eye_color() const
	{
		return eye_color_;
	}

	void set_eye_color(const std::string eye_color)
	{
		eye_color_ = eye_color;
	}

	std::string get_favourite_series() const
	{
		return favourite_series_;
	}

	void set_favourite_series(const std::string favourite_series)
	{
		favourite_series_ = favourite_series;
	}

	int get_age() const
	{
		return age_;
	}

	void set_age(const int age)
	{
		age_ = age;
	}

	void print() const;

private:
	std::string name_;
	std::string eye_color_;
	std::string favourite_series_;
	int age_;
};

void Person::print() const
{
	std::cout << get_name() << " is " << age_ << " years old.\n"
		<< "He has a " << eye_color_ << " eye color. "
		<< get_name() << " likes to watch TV series "
		<< favourite_series_<< "." << std::endl;
}

int main()
{
	Person person1("Harry", "green", "Black Mirror", 23);
	person1.print();

	Person person2("Tim", "blue", "Mr. Roberts", 26);
	person2.print();

	return 0;
}
