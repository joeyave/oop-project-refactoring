#include<iostream>

int main()
{
	const float VAL = 2.0f;
	
	float result = (VAL + 1) * 2;
	std::cout << "Result: " << result << ". Expected result: 6" << std::endl;

	result = (VAL + 1) * ((VAL + 2) * 2);
	std::cout << "Result: " << result << ". Expected result: 24" << std::endl;

	result = (VAL - 1) * 2 + 2 * 2;
	std::cout << "Result: " << result << ". Expected result: 6" << std::endl;

	result = (VAL + VAL) * (VAL + VAL) * 2;
	std::cout << "Result: " << result << ". Expected result: 32" << std::endl;

	result = static_cast<int>(VAL) % 2 * (VAL + 2 * 2);
	std::cout << "Result: " << result << ". Expected result: 0" << std::endl;
}
