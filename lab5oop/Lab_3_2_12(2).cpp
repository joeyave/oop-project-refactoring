#include <iostream>

int main()
{
	int matrix[10][10] = {};

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			*(&matrix[0][0] + (i * 10 + j)) = (i + 1) * (j + 1);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout.width(4);
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}

	return 0;
}
