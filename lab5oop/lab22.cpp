#include <iostream>
#include <vector>

class Matrix
{
private:
	std::vector<std::vector<int>> arr_;
	int n_;

	friend std::ostream& operator<<(std::ostream& out, Matrix& x);
	friend std::istream& operator>>(std::istream& in, Matrix& x);
};

std::ostream& operator<<(std::ostream& out, Matrix& x)
{
	for (int i = 0; i < x.n_; i++)
	{
		for (int j = 0; j < x.n_; j++)
		{
			out << x.arr_[i][j] << " ";
		}
		out << std::endl;
	}
	out << x.n_ << " " << x.n_;
	return out;
}

std::istream& operator>>(std::istream& in, Matrix& x)
{
	in >> x.n_;
	int value;

	for (int i = 0; i < x.n_; i++)
	{
		std::vector<int> row;
		for (int j = 0; j < x.n_; j++)
		{
			in >> value;
			row.push_back(value);
		}
		x.arr_.push_back(row);
	}

	return in;
}

int main()
{
	Matrix matrix;
	std::cin >> matrix;
	std::cout << matrix;

	return 0;
}
