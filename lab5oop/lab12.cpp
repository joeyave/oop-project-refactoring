#include<string>
#include<iostream>
#include <sstream>

int main()
{
	std::string sentence, line;

	while (getline(std::cin, sentence))
	{
		std::istringstream tr(sentence);

		while (tr >> line)
			std::cout << line << ' ';

		std::cout << std::endl;
	}

	std::cout << sentence << "\n";

	return 0;
}
