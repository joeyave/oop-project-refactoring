#include <iostream>
#include <string>
#include <windows.h>

struct Node
{
	int value;
	Node* left, *right;
};

void push(const int value, Node*& node)
{
	if (!node)
	{
		node = new Node;
		node->value = value;
		node->left = node->right = nullptr;
		return;
	}

	if (node->value > value)
	{
		push(value, node->left);
	}
	else
	{
		push(value, node->right);
	}
}

void clear(Node* root)
{
	if (!root)
	{
		return;
	}

	clear(root->left);
	clear(root->right);
	delete root;
}

std::ostream& inorder_recursive(std::ostream& out, Node* node)
{
	if (node == nullptr)
	{
		return out;
	}

	inorder_recursive(out, node->left);
	out << node->value << '\n';
	return inorder_recursive(out, node->right);
}

std::ostream& operator<<(std::ostream& out, Node* node)
{
	return inorder_recursive(out, node);
}

std::istream& operator>>(std::istream& in, Node*& node)
{
		std::cout << "Input integer data to push. Input stop to stop :)";
	while (true)
	{
		std::string ans;
		std::cin >> ans;
		if (ans == "stop")
		{
			break;
		}
		push(std::stoi(ans), node);
	}
	return in;
}

int main()
{
	Node* root = nullptr;
	
	std::cin >> root;
	std::cout << root;
	clear(root);

	return 0;
}
