#include <iostream>

void metric(const double m)
{
	const double tf = 3.2808 * m;
	const double ft = floor(tf);
	const double in = (tf - ft) * 12;
	std::cout << ft << "'" << in << "''" << std::endl;
}

void imperial(const double ft, const double in)
{
	const double m = (ft * 12 + in) * 0.0254;
	std::cout << m << "m" << std::endl;
}

void measurement_systems()
{
	int ans;
	double m, ft, in;

	std::cout << "For Metric, enter 0. For Imperial, enter 1." << std::endl;
	std::cin >> ans;

	if (ans == 0)
	{
		std::cout << "Metric method. How many Meters?" << std::endl;
		std::cin >> m;
		metric(m);
	}
	else if (ans == 1)
	{
		std::cout << "Imperial method. How many Feet?" << std::endl;
		std::cin >> ft;
		std::cout << "How many Inches?" << std::endl;
		std::cin >> in;
		imperial(ft, in);
	}
	else
	{
		std::cout << "Wrong input!" << std::endl;
	}
}

int main()
{
	measurement_systems();

	return 0;
}
