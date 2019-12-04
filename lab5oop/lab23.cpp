#include <iostream>
#include <fstream>

class Stack
{
public:
	explicit Stack(const int size)
	{
		// что-то сделать
		if (size < 0)
		{
			throw new std::exception("Negative_Value");
		}

		size_ = size;
		arr_ = new int[size_];
		top_ = arr_;
	}

	~Stack()
	{
		delete arr_;
	}

	bool is_empty() const
	{
		if (top_ > arr_)
		{
			return false;
		}
		return true;
	}

	bool is_full() const
	{
		if (top_ - arr_ < size_)
			return false;
		return true;
	}

	bool push(const int val)
	{
		const bool res = !is_full();
		if (res)
		{
			*top_ = val;
			top_++;
		}
		return res;
	}

	bool pop()
	{
		const bool res = !is_empty();
		if (res)
		{
			top_--;
		}
		return res;
	}

	bool pop(int* ret)
	{
		const bool res = !is_empty();
		if (res)
		{
			top_--;
			*ret = *top_;
		}
		return res;
	}

private:
	int* arr_;
	int* top_;
	int size_;
};

int main()
{
	int n;
	std::cout << "Count push: ";
	std::cin >> n;

	Stack s(n);

	int number;
	for (int i = 0; i <= n; i++)
	{
		std::cin >> number;
		s.push(number);
		std::cout << std::endl;
	}

	std::cout << "Count pop: ";
	std::cin >> n;

	for (int i = 0; i <= n; i++)
	{
		if (s.pop(&number))
			std::cout << number << std::endl;
		else
			std::cout << "Exception: stack is empty." << std::endl;
	}

	return 0;
}
