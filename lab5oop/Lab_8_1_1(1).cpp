#include <iostream>
#include <vector>

class Matrix
{
public:
	friend std::ostream& operator<<(std::ostream& out, Matrix& x);
	friend std::istream& operator>>(std::istream& in, Matrix& x);
private:
	std::vector<std::vector<int>> arr_;
	int n_;
};

std::ostream& operator<<(std::ostream& out, Matrix& x)
{
	for (int i = 0; i < x.n_; i++)
	{
		for (int j = 0; j < x.n_; j++)
			out << x.arr_[i][j] << " ";
		out << std::endl;
	}
	out << x.n_ << " " << x.n_;
	return out;
}

std::istream& operator>>(std::istream& in, Matrix& x)
{
	in >> x.n_;
	int a;

	for (int i = 0; i < x.n_; i++)
	{
		std::vector<int> row;
		for (int j = 0; j < x.n_; j++)
		{
			in >> a;
			row.push_back(a);
		}
		x.arr_.push_back(row);
	}

	return in;
}

int main()
{
	Matrix a;
	std::cin >> a;
	std::cout << a;

	return 0;
}
