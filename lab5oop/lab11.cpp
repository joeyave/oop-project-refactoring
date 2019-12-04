#include <iostream>
#include <string>
#include <vector>

const int LETTERS_IN_ALPHABET = 26;

bool check_pangram(std::string& input_string)
{
	// Hash table.
	std::vector<bool> marks(LETTERS_IN_ALPHABET, false);

	for (char letter : input_string)
	{
		if (std::isupper(letter))
		{
			marks[letter - 'A'] = true;
		}
		else if (std::islower(letter))
		{
			marks[letter - 'a'] = true;
		}
	}

	for (auto mark : marks)
	{
		if (mark == false)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	std::string input;
	getline(std::cin, input);

	if (check_pangram(input))
	{
		std::cout << "Pangram!" << std::endl;
	}
	else
	{
		std::cout << "Not a pangram." << std::endl;
	}
	return 0;
}
