//BST CLASS

using namespace std;
#include <iostream>
#include <fstream>
#include <istream>
#include <string>


class BST
{
private:
	struct Node
	{
		char character;
		string morseCode;
		Node *pLeft;
		Node *pRight;
	};

	Node *root = nullptr;

	void insert(Node *&, Node *&);
	void print_tree(Node *);
	void destroy_sub_tree(Node *);

public:
	BST();

	~BST()
	{ 
		destroy_sub_tree(root); 
	}

	void search();
};