#include<iostream>
#include <string>

int main()
{
	std::string name;
	const int N = 3;
	for (int i = 0; i < N; i++)
	{
		std::cout << "What is your name? ";
		getline(std::cin, name);

		std::cout << "Hello, " << name << "!\n";
		std::cout << std::endl;
	}
}
