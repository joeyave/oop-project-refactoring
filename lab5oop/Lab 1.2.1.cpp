#include<iostream>
#include <string>

int main()
{
	std::string name;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "What is your name? ";
		getline(std::cin, name);

		std::cout << "Hello, " << name << "!\n";
		std::cout << std::endl;
	}
}
