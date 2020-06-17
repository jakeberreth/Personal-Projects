/********************************************************
Name:            Jake Berreth
Project: Digital Music Manager
Date: September 19, 2019
*********************************************************/

#include "DigitalMusicManager.h"
#include "DigitalMusicManagerTests.h"

int main()
{

	int done = 0;
	int option = 0;
	char doneStr[10];

	Record newData = {"0", "0", "0", "0", 0, 0, 0, 0}; 
	Node *head = NULL;
	char line[200];

	//while loop to return to the main menu after a task has been completed
	while (done == 0)
	{
		system("cls");
		option = main_menu();
		system("cls");
		if (option == 1)
		{
			FILE *pInput = fopen("musicPlayList.csv", "r");
			int i = 0;
			//get one line from the file and extract the attributes
			while (fgets(line, 200, pInput) != NULL)
			{
				newData = extract_attributes(pInput, line);
				insert_front(&head, newData);
				i++;
			}
		}
		if (option == 2)
		{
			FILE *pOutput = fopen("musicPlayList.csv", "w");
			store_attributes(head, pOutput); //does work, just not while the program is running
		}
		if (option == 3)
		{
			print_list(head);
		}
		if (option == 4)
		{
			newData = get_info();
			insert_front(&head, newData);
		}
		if (option == 5)
		{
			delete_node(&head);
		}
		if (option == 6)
		{
			edit_list(head);
		}
		if (option == 8)
		{
			rate_artist(head);
		}
		if (option == 9)
		{
			play_list(head);
		}
		if (option == 10)
		{
			srand(time(0));
			int listLength = get_list_length(head);
			for (int i = 0; i < listLength; ++i)
			{
				int randomSong = rand() % listLength + 1;
				shuffle_play(head, listLength, randomSong);
			}
		}
		if (option == 11)
		{
			FILE *pOutput2 = fopen("musicPlayList.csv", "w");
			store_attributes(head, pOutput2);
			strcpy(doneStr, "yes");
		}
		if (strcmp(doneStr, "yes") != 0)
		{
			printf("Are you done? Enter yes or no: ");
			scanf("%s", doneStr);
			if (strcmp(doneStr, "no") == 0)
			{
				done = 0;
			}
			else {
				done = 1;
			}
			//check if the input was invalid, and ask for another entry
			while (strcmp(doneStr, "no") != 0 && strcmp(doneStr, "yes") != 0)
			{
				printf("Are you done? Enter yes or no: ");
				scanf("%s", doneStr);
				if (strcmp(doneStr, "no") != 0 && strcmp(doneStr, "yes") != 0)
				{
					done = 1;
				}
				else {
					done = 0;
				}
			}
		}
		else {
			done = 1;
		}
	}
}
