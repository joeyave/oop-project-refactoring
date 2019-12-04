#include <iostream>
#include <fstream>

class Stack
{
public:
	explicit Stack(const size_t size)
	{
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
	size_t size_;

	friend std::istream& operator>>(std::istream& in, Stack& stack);
	friend std::ostream& operator<<(std::ostream& out, Stack& stack);

};

std::istream& operator>>(std::istream& in, Stack& stack)
{	
	std::cout << "Input elements separated by space: " << std::endl;

	int value;
	for (size_t i = 0; i <= stack.size_; i++)
	{
		in >> value;
		stack.push(value);
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, Stack& stack)
{
	for (size_t i = 0; i <= stack.size_; i++)
	{
		int temp;
		if (stack.pop(&temp))
		{
			std::cout << temp << std::endl;
		}
		else
		{
			std::cout << "Stack is empty." << std::endl;
		}
	}

}

int main()
{
	int size;
	std::cout << "Input size: ";
	std::cin >> size;

	Stack stk(size);
	std::cin >> stk;
	std::cout << stk;
	
	return 0;
}
