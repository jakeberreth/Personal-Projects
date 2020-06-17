//FILE FOR BST CLASS Function Definitions

#include "MorseCodeTree.h"

//constructor
BST::BST()
{
	ifstream inFile;
	char inputFileName[] = "MorseTable.txt";
	inFile.open(inputFileName, ios::in);

	int i = 0;
	Node *newNode = nullptr;
	string temp;
	while (i < 39)
	{
		newNode = new Node; //malloc doesn't work
		newNode->character = inFile.get();
		inFile.get();
		getline(inFile, temp); 
		newNode->morseCode = temp;
		newNode->pLeft = nullptr;
		newNode->pRight = nullptr;
		insert(root, newNode);
		i++;
	}
	inFile.close();
	print_tree(root);
}

//destructor
void BST::destroy_sub_tree(Node *pTree)
{
	if (pTree)
	{
		if (pTree->pLeft)
		{
			destroy_sub_tree(pTree->pLeft);
		}
		if (pTree->pRight)
		{
			destroy_sub_tree(pTree->pRight);
		}
		delete pTree;
	}
}

//insert node into the binary search tree
void BST::insert(Node *&pTree, Node *&newNode)
{
	if (pTree == nullptr)
	{
		pTree = newNode;
	}
	else if (newNode->character < pTree->character)
	{
		insert(pTree->pLeft, newNode);
	}
	else
	{
		insert(pTree->pRight, newNode);
	}
}

//print the tree
void BST::print_tree(Node *pTree) 
{
	if (pTree)
	{
		print_tree(pTree->pLeft);
		cout << pTree->character << endl
			 << pTree->morseCode << endl;
		print_tree(pTree->pRight);
	}
}

//convert the message in a file into morse code, and write to a file
void BST::search()
{
	ifstream convertFile;
	char convertFileName[] = "Convert.txt";
	convertFile.open(convertFileName, ios::in);

	ofstream outFile;
	char outFileName[] = "ConvertedString.txt";
	outFile.open(outFileName, ios::out);

	char character = ' ';

	Node *pTree = nullptr;
	while (!convertFile.eof()) 
	{
		pTree = root;

		character = convertFile.get();
		if (character >= 'a' && character <= 'z')
		{
			character = character - ('a' - 'A');
		}
		if (character == ' ')
		{
			outFile << "  ";
		}
		else {
			while (pTree)
			{
				if (pTree->character == character)
				{
					outFile << pTree->morseCode << " ";
					break;
				}
				else if (character < pTree->character)
				{
					pTree = pTree->pLeft;
				}
				else
				{
					pTree = pTree->pRight;
				}
			}
		}
	}
	convertFile.close();
}

//reference is not an address, reference table is made
