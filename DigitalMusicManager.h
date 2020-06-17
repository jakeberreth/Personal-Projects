//HEADER FILE: Struct definitions and function prototypes

#pragma once

#define _CRT_SECURE_NO_WARNINGS //Has to be before includes to work

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Duration struct
typedef struct duration
{
	int seconds;
	int minutes;
}Duration;

//Record struct
typedef struct record
{
	//requires temp string because this only have enough space allocated for a pointer
	//so you have to reassign the pointer
	char *artist;
	char *album;
	char *title;
	char *genre;
	Duration songLength;
	int timesPlayed;
	int rating;
}Record;

//Node struct
typedef struct node
{
	Record data;
	struct node *pNext;
	struct node *pPrev;
}Node;

int main_menu();
Record get_info();
Record extract_attributes(FILE *pInput, char tempArray[]);
Node* make_node(Record newData);
int insert_front(Node **head, Record newData);
void print_list(Node *head_ref);
void delete_node(Node **head_ref);
void edit_list(Node *head_ref);
int get_list_length(Node *head_ref);
void shuffle_play(Node *head_ref, int listLength, int randomSong);
void rate_artist(Node *head_ref);
void store_attributes(Node *head_ref, FILE *pOutput);
int isEmpty(Node *pNode);