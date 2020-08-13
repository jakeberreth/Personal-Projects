//Function Definitions

#include "AVLTree.h"

//Create a new node
Node* make_node(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->pLeft = NULL;
	newNode->pRight = NULL;

	return newNode;
}

//Find the height of the left subtree
int find_height_left(Node* root) {
	if (root == NULL) {
		return 0;
	}
	else
	{
		int left = find_height_left(root->pLeft);
		int right = find_height_left(root->pRight);
		if (left > right) {
			return left + 1;
		}
		else {
			return right + 1;
		}
	}
}

//Find the height of the right subtree
int find_height_right(Node* root) {
	if (root == NULL) {
		return 0;
	}
	else
	{
		int left = find_height_left(root->pLeft);
		int right = find_height_left(root->pRight);
		if (left > right) {
			return left + 1;
		}
		else {
			return right + 1;
		}
	}
}

//Rotate left
Node* left_rotate(Node* root) {
	Node* temp = root->pRight;
	root->pRight = temp->pLeft;
	temp->pLeft = root;
	return temp;
}

//Rotate right
Node* right_rotate(Node* root) {
	Node* temp = root->pLeft;
	root->pLeft = temp->pRight;
	temp->pRight = root;
	return temp;
}

//Insert a node into the tree
Node* insert(Node* root, int value) {
	int heightLeft = 0;
	int heightRight = 0;
	int balanceFactor = 0;

	//Regular insertion
	if (root == NULL) {
		root = make_node(value);
	}
	else if (value <= root->data) {
		root->pLeft = insert(root->pLeft, value);
	}
	else {
		root->pRight = insert(root->pRight, value);
	}

	//Find the heights of the subtrees
	heightLeft = find_height_left(root->pLeft);
	heightRight = find_height_right(root->pRight);

	//Compare the heights to determine the balance factor
	balanceFactor = heightLeft - heightRight;

	//left-left
	if (balanceFactor > 1 && value < root->pLeft->data) {
		return right_rotate(root);
	}

	//left-right
	if (balanceFactor > 1 && value > root->pLeft->data) {
		root->pLeft = left_rotate(root->pLeft);
		return right_rotate(root);
	}

	//right-right
	if (balanceFactor < -1 && value > root->pRight->data) {
		return left_rotate(root);
	}

	//right-left
	if (balanceFactor < -1 && value < root->pRight->data) {
		root->pRight = right_rotate(root->pRight);
		return left_rotate(root);
	}

	return root;
}

//Display the contents of the tree with preorder traversal
void preorder(Node* node) {
	if (node == NULL) {
		return;
	}

	printf("%d ", node->data);
	preorder(node->pLeft);
	preorder(node->pRight);
}


