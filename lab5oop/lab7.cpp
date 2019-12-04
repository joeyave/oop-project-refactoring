#include <iostream>

int main()
{
	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	const int N = sizeof vector / sizeof vector[0];

	int* min = vector;

	for (int i = 1; i < N; i++)
	{
		if (vector[i] < *min)
		{
			min = &vector[i];
		}
	}
	std::cout << "Min: " << *min << "\tplace: " << min << std::endl;

	return 0;
}
