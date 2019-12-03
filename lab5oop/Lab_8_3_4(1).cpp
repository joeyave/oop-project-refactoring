#include <iostream>
#include <string>
#include <conio.h>

struct Node
{
	int value;                        
	Node *left, *right;
};

void push(const int a, Node *&t)
{
	if (!t)                   
	{
		t = new Node;                
		t->value = a;                
		t->left = t->right = nullptr;       
		return;                         
	}

	if (t->value > a) 
	{
		push(a, t->left);
	} else {
		push(a, t->right);
	}
}

void clear(Node *root)
{
	if (!root) return;
	clear(root->left);
	clear(root->right);
	delete root;
}

std::ostream& inorder_recursive(std::ostream &out, Node *current)
{	
	if (current == nullptr) return out;	
	inorder_recursive(out, current->left);
	out << current->value << '\n';	
	return inorder_recursive(out, current->right);
}

std::ostream &operator << (std::ostream &ostr, Node *bs)
{
	return inorder_recursive(ostr, bs);
}


int main()
{	

	Node *root = nullptr;
	int n;                              
	int s;
	std::cin >> n;

	for(int i = 0; i<n; ++i)
	{
		std::cin >> s;                       
		push(s, root);                
	}

	std::cout << root;
	clear(root);

    return 0;
}

