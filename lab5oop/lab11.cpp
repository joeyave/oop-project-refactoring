#include <iostream>
#include <string>

const int LETTER_NUM = 26;
const int ALFA_START = 97;

int main()
{
	std::string input_string;
	getline(std::cin, input_string);
	int alphabet_tab = 0;
	int alphabet[LETTER_NUM];
	int flag = 0;

	for (int i = 0; i < LETTER_NUM; i++)
		alphabet[i] = 0;

	for (int i = 0; i < input_string.length(); i++)
	{
		const int INSERT_NUM = tolower(input_string[i]) - 'a';

		if (INSERT_NUM < 0 || INSERT_NUM > 25)
			continue;

		if (alphabet[INSERT_NUM] == 0)
		{
			alphabet_tab++;
		}

		if (alphabet_tab >= LETTER_NUM)
		{
			flag = 1;
			break;
		}

		alphabet[INSERT_NUM]++;
	}

	for (int i = 0; i < LETTER_NUM; i++)
	{
		std::cout << static_cast<char>(i + ALFA_START) << " - " << alphabet[i] << std::endl;
	}

	if (flag)
	{
		std::cout << "Pangram." << std::endl;
	}
	else
	{
		std::cout << "Not pangram." << std::endl;
	}

	return 0;
}
