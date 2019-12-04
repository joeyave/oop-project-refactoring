#include<iostream>
#include<string>

class Person
{
public:
	Person(std::string name, std::string eye_color, std::string favourite_series, int age)
	{
		name_ = name;
		eye_color_ = eye_color;
		favourite_series_ = favourite_series;
		age_ = age;
	}

	std::string get_name()
	{
		return name_;
	}

	void set_name(std::string name)
	{
		name_ = name;
	}

	std::string get_eye_color()
	{
		return eye_color_;
	}

	void set_eye_color(std::string eye_color)
	{
		eye_color_ = eye_color;
	}

	std::string get_favourite_series()
	{
		return favourite_series_;
	}
private:
	std::string name_;
	std::string eye_color_;
	std::string favourite_series_;
	int age_;
};

void print(Person* person)
{
	std::cout << person->name_ << " is " << person->age << " years old.\n"
		<< "He has a " << person->eye_color_ << " eye color. "
		<< person->name_ << " likes to watch TV series "
		<< person->favourite_series_ << "." << std::endl;
}

int main()
{
	Person person1;
	person1.name_ = "Harry";
	person1.age = 23;
	person1.eye_color_ = "green";
	person1.favourite_series_ = "Black Mirror";
	std::cout << "Meet " << person1.name_ << "!" << std::endl;
	print(&person1);

	Person person2;
	person2.name_ = "Tim";
	person2.age = 26;
	person2.eye_color_ = "blue";
	person2.favourite_series_ = "Mr. Robot";
	std::cout << "Meet " << person2.name_ << "!" << std::endl;
	print(&person2);

	return 0;
}
