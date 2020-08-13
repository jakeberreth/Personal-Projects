//Function Prototypes and Struct Declarations

#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	Node* pLeft;
	Node* pRight;
}Node;

Node* make_node(int value);
int find_height_left(Node* root);
int find_height_right(Node* root);
Node* left_rotate(Node* root);
Node* right_rotate(Node* root);
Node* insert(Node* root, int value);
void preorder(Node* node);

