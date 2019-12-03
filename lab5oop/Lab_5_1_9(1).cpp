#include<iostream>
#include<string>

class Person
{
public:
	std::string name;
	std::string eye_color;
	std::string fav_series;
	int age;
};

void print(Person* person)
{
	std::cout << person->name << " is " << person->age << " years old.\n"
		<< "He has a " << person->eye_color << " eye color. "
		<< person->name << " likes to watch TV series "
		<< person->fav_series << "." << std::endl;
}

int main()
{
	Person person1;
	person1.name = "Harry";
	person1.age = 23;
	person1.eye_color = "green";
	person1.fav_series = "Black Mirror";
	std::cout << "Meet " << person1.name << "!" << std::endl;
	print(&person1);

	Person person2;
	person2.name = "Tim";
	person2.age = 26;
	person2.eye_color = "blue";
	person2.fav_series = "Mr. Robot";
	std::cout << "Meet " << person2.name << "!" << std::endl;
	print(&person2);

	system("pause");
	return 0;
}
