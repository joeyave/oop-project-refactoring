#include <iostream>
#include <string>

int main()
{
	std::string input_string;
	getline(std::cin, input_string);
	int alphabet_tab = 0;
	int alphabet[26];
	int flag = 0;

	for (int i = 0; i < 26; i++)
		alphabet[i] = 0;

	for (int i = 0; i < input_string.length(); i++)
	{
		const int insert_num = tolower(input_string[i]) - 'a';
		if (insert_num < 0 || insert_num > 25)
			continue;
		
		if (alphabet[insert_num] == 0)
			alphabet_tab++;
		
		if (alphabet_tab >= 26)
		{
			flag = 1;
			break;
		}
		
		alphabet[insert_num]++;
	}

	for (int i = 0; i < 26; i++)
	{
		std::cout << static_cast<char>(i + 97) << " - " << alphabet[i] << std::endl;
	}

	if (flag)
		std::cout << "Pangram." << std::endl;
	else
		std::cout << "Not pangram." << std::endl;

	return 0;
}
