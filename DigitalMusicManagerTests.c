#include "PA2.h"

//Tests insert function
void test_insert()
{
	Record newData = { "Perry, Katy", "Witness", "Chained to the Rhythm", "pop", 4, 36, -1, 6 };
	Node *head = NULL;
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data.artist = newData.artist;
	newNode->data.album = newData.album;
	newNode->data.title = newData.title;
	newNode->data.genre = newData.genre;
	newNode->data.songLength.minutes = newData.songLength.minutes;
	newNode->data.songLength.seconds = newData.songLength.seconds;
	newNode->data.timesPlayed = newData.timesPlayed;
	newNode->data.rating = newData.rating;
	newNode->pNext = NULL;
	newNode->pPrev = NULL;
	newNode->pNext = head;
	head = newNode;
	int success = 0;

	//test case: times played less than 0
	if (newData.timesPlayed < 0)
	{
		printf("WARNING!!! A value for times played that is less than 0 has been inserted into the list.\n");
		success = 1;
	}

	//test case: rating greater than 5 or less than 1
	if (newData.rating > 5 || newData.rating < 1)
	{
		printf("WARNING!!! A value for rating that is greater than 5 or less than 1 has been inserted into the list.\n");
		success = 1;
	}

	//test case: head pointer not updated
	if (head == NULL)
	{
		printf("WARNING!!! Insertion of the node failed. The head pointer is pointing to NULL.\n");
		success = 1;
	}
	if (success != 1)
	{
		printf("Insert Successful!\n");
	}
}

//Tests delete function
void test_delete()
{
	Record newData = { "Perry, Katy", "Witness", "Chained to the Rhythm", "pop", 4, 36, 5, 3 };
	Node *head = NULL;
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data.artist = newData.artist;
	newNode->data.album = newData.album;
	newNode->data.title = newData.title;
	newNode->data.genre = newData.genre;
	newNode->data.songLength.minutes = newData.songLength.minutes;
	newNode->data.songLength.seconds = newData.songLength.seconds;
	newNode->data.timesPlayed = newData.timesPlayed;
	newNode->data.rating = newData.rating;
	newNode->pNext = NULL;
	newNode->pPrev = NULL;
	newNode->pNext = head;
	head = newNode;
	int success = 0;
	char songTitle[50];
	Node *traverse = head;
	Node *current = head;
	Node *prev;
	int done = 0;
	printf("Which record would you like to edit?\n");
	printf("Your options are: \n\n");
	while (isEmpty(traverse) != 1)
	{
		printf("%s: %s\n", traverse->data.artist, traverse->data.title);
		traverse = traverse->pNext;
	}
	printf("\nEnter song title. YOU MUST ENTER EXACTLY AS WRITTEN ABOVE: ");
	gets(songTitle);
	gets(songTitle);
	if (isEmpty(current))
	{
		printf("The list is empty!");
		return;
	}
	if (strcmp(current->data.title, songTitle) == 0)
	{
		head = current->pNext;
		free(current);
		return;
	}
	while (current != NULL && strcmp(current->data.title, songTitle) != 0)
	{
		prev = current;
		current = current->pNext;
	}
	prev->pNext = current->pNext;
	free(current);

	//test case: head pointer not updated and delete failed
	if (head != NULL)
	{
		printf("The node has failed to be deleted.\n");
	}
}