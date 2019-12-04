#include <iostream>
#include <string>
#include <conio.h>

struct Node
{
	int value;
	Node* left, * right;
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

std::ostream& operator <<(std::ostream& out, Node* node)
{
	return inorder_recursive(out, node);
}


int main()
{
	Node* root = nullptr;
	int value;
	int size;
	std::cin >> value;

	for (int i = 0; i < value; ++i)
	{
		std::cin >> size;
		push(size, root);
	}

	std::cout << root;
	clear(root);

	return 0;
}
