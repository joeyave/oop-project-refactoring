#include<iostream>

int main()
{
	const float v = 2.0f;
	
	float result = (v + 1) * 2;
	std::cout << "Result: " << result << ". Expected result: 6" << std::endl;

	result = (v + 1) * ((v + 2) * 2);
	std::cout << "Result: " << result << ". Expected result: 24" << std::endl;

	result = (v - 1) * 2 + 2 * 2;
	std::cout << "Result: " << result << ". Expected result: 6" << std::endl;

	result = (v + v) * (v + v) * 2;
	std::cout << "Result: " << result << ". Expected result: 32" << std::endl;

	result = static_cast<int>(v) % 2 * (v + 2 * 2);
	std::cout << "Result: " << result << ". Expected result: 0" << std::endl;
}
