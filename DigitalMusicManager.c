//FUNCTION DECLARATIONS

#include "PA2.h"

//Displays the main menu and gets the chosen task as an integer
int main_menu()
{
	int option = 0;
	printf("           MAIN MENU\n");
	printf("///////////////////////////////\n");
	printf("1. LOAD\n2. STORE\n3. DISPLAY\n4. INSERT\n5. DELETE\n6. EDIT\n7. SORT\n8. RATE\n9. PLAY\n10. SHUFFLE\n11. EXIT\n");
	printf("///////////////////////////////\n");
	printf("Please choose an option from the main menu. You must select LOAD first: ");
	scanf("%d", &option);
	switch (option)
	{
	case 1:
		printf("You chose LOAD.\n");
		return option;
		break;
	case 2:
		printf("You chose STORE.\n");
		return option;
		break;
	case 3:
		printf("You chose DISPLAY.\n");
		return option;
		break;
	case 4:
		printf("You chose INSERT.\n");
		return option;
		break;
	case 5:
		printf("You chose DELETE.\n");
		return option;
		break;
	case 6:
		printf("You chose EDIT.\n");
		return option;
		break;
	case 7:
		printf("You chose SORT.\n");
		return option;
		break;
	case 8:
		printf("You chose RATE.\n");
		return option;
		break;
	case 9:
		printf("You chose PLAY.\n");
		return option;
		break;
	case 10:
		printf("You chose SHUFFLE.\n");
		return option;
		break;
	case 11:
		printf("You chose EXIT.\n");
		return option;
		break;
	default:
		printf("That option is invalid.\n");
		return option;
	}
}

//Gets into as input and puts the data into Record newData
//(not being used in PA 2, will be called in PA 3)
Record get_info()
{
	Record newData = { "0", "0", "0", "0", 0, 0, 0, 0 };

	char strTemp[20];
	int length = 0;
	printf("Enter the artist name: ");
	gets(strTemp); //gets the new line character after you type in the number "4"
	gets(strTemp);
	length = strlen(strTemp);
	newData.artist = (char*)malloc(length * sizeof(char));
	strcpy(newData.artist, strTemp);

	printf("Enter the album title: ");
	gets(strTemp);
	length = strlen(strTemp);
	newData.album = (char*)malloc(length * sizeof(char));
	strcpy(newData.album, strTemp);

	printf("Enter the song title: ");
	gets(strTemp);
	length = strlen(strTemp);
	newData.title = (char*)malloc(length * sizeof(char));
	strcpy(newData.title, strTemp);

	printf("Enter the genre: ");
	gets(strTemp);
	length = strlen(strTemp);
	newData.genre = (char*)malloc(length * sizeof(char));
	strcpy(newData.genre, strTemp);

	printf("Enter the minutes: ");
	scanf("%d", &newData.songLength.minutes);

	printf("Enter the seconds: ");
	scanf("%d", &newData.songLength.seconds);

	printf("Enter times played: ");
	scanf("%d", &newData.timesPlayed);

	printf("Enter the rating: ");
	scanf("%d", &newData.rating);
	
	return newData;
}

//Extracts the attributes from the file and places them into a Record as newData
Record extract_attributes(FILE *pInput, char tempArray[])
{
	Record newData;

	int length = 0, i = 0, choice = 0;
	char tempStr[100];
	for (i; i < strlen(tempArray); ++i)
	{
		if (tempArray[i] == ',' && tempArray[i + 1] == ' ')
		{
			strcpy(tempStr, &tempArray[i + 1]);
			strcpy(&tempArray[i], tempStr);
		}
	}
	
	char *temp = strtok(tempArray, ",");
	newData.artist = (char*)malloc(strlen(temp) * sizeof(char));
	strcpy(newData.artist, temp);

	temp = strtok(NULL, ",");
	newData.album = (char*)malloc(strlen(temp) * sizeof(char));
	strcpy(newData.album, temp);

	temp = strtok(NULL, ",");
	newData.title = (char*)malloc(strlen(temp) * sizeof(char));
	strcpy(newData.title, temp);

	temp = strtok(NULL, ",");
	newData.genre = (char*)malloc(strlen(temp) * sizeof(char));
	strcpy(newData.genre, temp);

	newData.songLength.minutes = atoi(strtok(NULL, ":"));
	newData.songLength.seconds = atoi(strtok(NULL, ","));
	newData.timesPlayed = atoi(strtok(NULL, ",")); 
	newData.rating = atoi(strtok(NULL, "\0"));

	return newData;
}

//Makes a new node and assigns the data in newData to it, returns the node
Node* make_node(Record newData)
{
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
	return newNode;
}

//Inserts the node at the front after calling make_node
int insert_front(Node** head, Record newData) //name is still just head, still just a pointer to a variable, but with the extra pointer, we dereference head
//The ** just means we have access to the head in main, as the address of head was passed in
{
	Node *newNode = make_node(newData); //changing the address pointed to
	newNode->pNext = *head;
	*head = newNode;

	if (*head != NULL)
	{
		return 1;
	}
	else {
		return 0;
	}
}

//Displays the list to the screen
void print_list(Node* head_ref)
{
	while (isEmpty(head_ref) != 1)
	{
		printf("Artist: %s\n", head_ref->data.artist); //head_ref is the node
		printf("Album: %s\n", head_ref->data.album);
		printf("Song Title: %s\n", head_ref->data.title);
		printf("Genre: %s\n", head_ref->data.genre);
		printf("Song length: %d:%d\n", head_ref->data.songLength.minutes, head_ref->data.songLength.seconds);
		printf("Times played: %d\n", head_ref->data.timesPlayed);
		printf("Rating: %d\n", head_ref->data.rating);
		head_ref = head_ref->pNext; //don't need value of pointer, don't need the address of pNext, just the value
		printf("\n"); //works with * and without, how would it be different with parentheses
	}
}

//Deletes a node from a the list
void delete_node(Node** head_ref)
{
	char songTitle[50];
	Node *traverse = *head_ref;
	Node *current = *head_ref;
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
		*head_ref = current->pNext;
		free(current);
		return;
	}
	while(current!= NULL && strcmp(current->data.title, songTitle) != 0)
	{
		prev = current;
		current = current->pNext;
	}
	prev->pNext = current->pNext;
	free(current);
}

//Edits the list based on the chosen artist and album names and stores new data into the linked list
void edit_list(Node *head_ref)
{
	char artist[50], album[50];
	int isCorrect = 0;
	Node *traverse = head_ref;
	printf("Which record would you like to edit?\n");
	printf("Your options are: \n\n");
	while (isEmpty(traverse) != 1)
	{
		printf("%s: %s\n", traverse->data.artist, traverse->data.album);
		traverse = traverse->pNext;
	}
	printf("\nEnter artist name. YOU MUST ENTER EXACTLY AS WRITTEN ABOVE: ");
	gets(artist);
	gets(artist);
	printf("Enter album name: ");
	gets(album);


	char attribute[50];
	char newAttributeStr[50];
	int newAttributeInt = 0, done = 0;
	while (isEmpty(head_ref) != 1 && done == 0)
	{
		if (strcmp(head_ref->data.artist, artist) == 0 && strcmp(head_ref->data.album, album) == 0)
		{
			done = 1;
			printf("Enter the attribute you would like to edit: ");
			gets(attribute);
			if (strcmp(attribute, "artist") == 0 || strcmp(attribute, "album") == 0 || strcmp(attribute, "title") == 0 || strcmp(attribute, "genre") == 0) 
			{
				printf("Enter the new attribute: ");
				scanf("%s", newAttributeStr);
			}
			else{
			if(strcmp(attribute, "times played"))
				printf("Enter the new attribute: ");
				scanf("%d", &newAttributeInt);
			}
			if (strcmp(attribute, "artist") == 0)
			{
				strcpy(head_ref->data.artist, newAttributeStr);
			}
			if (strcmp(attribute, "album") == 0)
			{
				strcpy(head_ref->data.album, newAttributeStr);
			}
			if (strcmp(attribute, "title") == 0)
			{
				strcpy(head_ref->data.title, newAttributeStr);
			}
			if (strcmp(attribute, "genre") == 0) 
			{
				strcpy(head_ref->data.genre, newAttributeStr);
			}
			if (strcmp(attribute, "minutes") == 0)
			{
				head_ref->data.songLength.minutes = newAttributeInt;
			}
			if (strcmp(attribute, "seconds") == 0)
			{
				head_ref->data.songLength.seconds = newAttributeInt;
			}
			if (strcmp(attribute, "times played") == 0)
			{
				head_ref->data.timesPlayed = newAttributeInt;
			}
			if (strcmp(attribute, "rating") == 0)
			{
				head_ref->data.rating = newAttributeInt;
			}
		}
		head_ref = head_ref->pNext;
	}
}

//Gets the length of a list
int get_list_length(Node *head_ref)
{
	int listLength = 0;
	Node *traverse = head_ref;
	while(isEmpty(traverse) != 1)
	{
		traverse = traverse->pNext;
		listLength++;
	}
	return listLength;
}

//Takes a random order for playing songs, and plays them in that order
void shuffle_play(Node *head_ref, int listLength, int randomSong)
{
	Node *traverse = head_ref;
	char songTitle[50];
	int done = 0;
	for (int i = 1; i <= randomSong; ++i)
	{
		if (i != randomSong)
		{
			traverse = traverse->pNext;
		}else 
		{
			strcpy(songTitle, traverse->data.title);
		}
	}
	Node *current = head_ref;
	srand(time(0));
	while (done == 0)
	{
		if (strcmp(current->data.title, songTitle) == 0)
		{
			printf("\nPlaying song entitled: %s\n", songTitle);
			int continuePlaying = 0;
			while (done == 0)
			{
				printf("Press 0 to continue to the next song: ");
				scanf("%d", &continuePlaying);
				if (continuePlaying == 0)
				{
					done = 1;
				}
			}
		}
		else
		{
			if (current->pNext == NULL)
			{
				current = current->pPrev;
			}
			else {
				current = current->pNext;
			}
		}
	}
}

//Rates an artist and stores the new rating in the linked list
void rate_artist(Node *head_ref)
{
	char artist[50], album[50];
	int rating = 0, done = 0;
	Node *traverse = head_ref;
	printf("Which record would you like to edit?\n");
	printf("Your options are: \n\n");
	while (isEmpty(traverse) != 1)
	{
		printf("%s: %s\n", traverse->data.artist, traverse->data.album);
		traverse = traverse->pNext;
	}
	printf("\nEnter artist name. YOU MUST ENTER EXACTLY AS WRITTEN ABOVE: "); 
	gets(artist);
	gets(artist);
	printf("Enter album name: ");
	gets(album);
	printf("What is your rating, from 1 to 5? ");
	scanf("%d", &rating);
	while (isEmpty(head_ref) != 1 && done == 0)
	{
		if (strcmp(head_ref->data.artist, artist) == 0 && strcmp(head_ref->data.album, album) == 0)
		{
			done = 1;
			head_ref->data.rating = rating;
		}
		head_ref = head_ref->pNext;
	}
}

//Asks for a starting song, and plays through all of the songs in the list
void play_list(Node *head_ref)
{
	char songTitle[50], goNext[10];
	int done = 0;
	Node *traverse = head_ref;
	printf("Which song would you like to begin at? \n");
	printf("Your options are: \n\n");
	while (isEmpty(traverse) != 1)
	{
		printf("%s: %s\n", traverse->data.artist, traverse->data.title);
		traverse = traverse->pNext;
	}
	printf("\n\n");
	printf("Enter song title. YOU MUST ENTER EXACTLY AS WRITTEN ABOVE: "); 
	gets(songTitle);
	gets(songTitle);
	while (isEmpty(head_ref) != 1 && done == 0) 
	{
		if (strcmp(head_ref->data.title, songTitle) == 0 || strcmp(goNext, "yes") == 0)
		{
			printf("Artist: %s\n", head_ref->data.artist);
			printf("Album: %s\n", head_ref->data.album);
			printf("Song Title: %s\n", head_ref->data.title);
			printf("Genre: %s\n", head_ref->data.genre);
			printf("Song length: %d:%d\n", head_ref->data.songLength.minutes, head_ref->data.songLength.seconds);
			printf("Times played: %d\n", head_ref->data.timesPlayed);
			printf("Rating: %d\n\n\n", head_ref->data.rating);
			printf("Go to next song? Type yes or no: ");
			scanf("%s", goNext);
			if (strcmp(goNext, "no") == 0)
			{
				done = 1;
			}
		}
		head_ref = head_ref->pNext;
		printf("\n");
		system("cls");
	}
}

//stores the attributes of each record into the musicPlayList.csv file
void store_attributes(Node *head_ref, FILE *pOutput)
{
	while (isEmpty(head_ref) != 1)
	{
		fprintf(pOutput, "%s%c", head_ref->data.artist, ',');
		fprintf(pOutput, "%s%c", head_ref->data.album, ',');
		fprintf(pOutput, "%s%c", head_ref->data.title, ',');
		fprintf(pOutput, "%s%c", head_ref->data.genre, ',');
		fprintf(pOutput, "%d:%d%c", head_ref->data.songLength.minutes, head_ref->data.songLength.seconds, ',');
		fprintf(pOutput, "%d%c", head_ref->data.timesPlayed, ',');
		fprintf(pOutput, "%d%c\n", head_ref->data.rating, ',');
		head_ref = head_ref->pNext;
	}
}

//Checks if the list is empty
int isEmpty(Node *pNode)
{
	int status = 0;
	if (pNode == NULL)
	{
		status = 1;
	}
	return status;
}


//for testing, do the task, look at what the program does, and then respond, maybe write a warning message


