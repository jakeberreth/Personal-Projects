//Name: Jake Berreth
//Date: 8/13/2020
//Title: AVL Tree

#include "AVLTree.h"

int main() {
	//Declare root node
	Node* root = NULL;

	//Insert values
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

	//Display the contents of the tree
	printf("Preorder traversal of the AVL tree is: \n");
	preorder(root);
	printf("\n\n");

	//End program
	return 0;
}