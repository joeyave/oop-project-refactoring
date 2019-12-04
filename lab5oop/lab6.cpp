#include <iostream>

void measurement_systems()
{
	int ans;
	float m, ft, in;

	std::cout << "For Metric, enter 0. For Imperial, enter 1." << std::endl;
	std::cin >> ans;

	switch (ans)
	{
	case 0:
		std::cout << "Metric method. How many Meters?" << std::endl;
		std::cin >> m;
		float tf = 3.2808 * m;
		ft = floor(tf);
		in = (tf - ft) * 12;
		std::cout << ft << "'" << in << "''" << std::endl;
		break;
	case 1:
		std::cout << "Imperial method. How many Feet?" << std::endl;
		std::cin >> ft;
		std::cout << "How many Inches?" << std::endl;
		std::cin >> in;
		m = (ft * 12 + in) * 0.0254;
		std::cout << m << "m" << std::endl;
	default:
		std::cout << "Wrong input!" << std::endl;
		break;
	}
}

int main()
{
	measurement_systems();

	return 0;
}
