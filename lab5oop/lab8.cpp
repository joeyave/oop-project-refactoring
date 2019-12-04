#include <iostream>
const int N = 10;
const int M = 10;

int main()
{

	int matrix[N][M] = {};

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			*(*(matrix + i) + j) = (i + 1) * (j + 1);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cout.width(4);
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}

	return 0;
}
