#include <iostream>
#include <vector>

class Matrix
{
public:
	Matrix()
	{
		size_ = 0;
	}

private:
	std::vector<std::vector<int>> arr_;
	size_t size_;

	friend std::ostream& operator<<(std::ostream& out, Matrix& matrix);
	friend std::istream& operator>>(std::istream& in, Matrix& matrix);
};

std::ostream& operator<<(std::ostream& out, Matrix& matrix)
{
	for (size_t i = 0; i < matrix.size_; i++)
	{
		for (size_t j = 0; j < matrix.size_; j++)
		{
			out << matrix.arr_[i][j] << " ";
		}
		out << std::endl;
	}
	out << matrix.size_ << " " << matrix.size_;
	return out;
}

std::istream& operator>>(std::istream& in, Matrix& matrix)
{
	std::cout << "Input size: ";
	std::cin >> matrix.size_;

	std::cout << "Input elements separated by space: " << std::endl;
	int value;

	for (size_t i = 0; i < matrix.size_; i++)
	{
		std::vector<int> row;
		for (size_t j = 0; j < matrix.size_; j++)
		{
			in >> value;
			row.push_back(value);
		}
		matrix.arr_.push_back(row);
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
