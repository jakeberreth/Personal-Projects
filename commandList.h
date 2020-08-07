#pragma once

using namespace std;
#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>
#include <string>
#include <time.h>
#include <random>
#include <math.h>
#include "Profiles.h"

//displays the main menu
int main_menu();
//gets an answer choice
int get_answer(int randomOrder, string correctDescription, string correctCommand, string randomDescription1, string randomDescription2, int pointTotal);

//List class
template <class t1, class t2>
class List
{
private:
	struct Node
	{
		t1 command;
		t2 description;
		Node *pNext;
	};
	Node *pHead = nullptr;
	int numberOfCommands;

public:
	List()
	{
		//constructor
	}
	void call_insert_front(t1 newCommand, t2 newDescription);
	void insert_front(Node **pHead, t1 newCommand, t2 newDescription);
	void call_print_list();
	void print_list(Node *pHead);
	int call_display_question(int pointTotal, int randomOrder[]);
	int display_question(Node *pHead, int pointTotal, int randomOrder[]);
	void call_remove(t1 removeCommand);
	void remove(Node **pHead, t1 removeCommand);
	void call_save_commands();
	void save_commands(Node *pHead);
	void set_number_of_commands(int numCommands)
	{
		numberOfCommands = numCommands;
	}
	int get_number_of_commands()
	{
		return numberOfCommands;
	}
};

//Loads the commands and descriptions from the file into a list
template<class t1, class t2>
int load_list(int listSize, List<t1, t2> &list) 
{
	ifstream inputFile;
	char inputFileName[] = "commands.csv";
	inputFile.open(inputFileName, ios::in);
	string command;
	string description;
	int i = 0, length = 0;
	while (!inputFile.eof()) 
	{
		getline(inputFile, command, ',');
		getline(inputFile, description, '\n');
		length = description.size();
		length = length - 2;
		char newDescription1[length + 1];
		for(int k = 0; k < length + 1; ++k)
		{
			newDescription1[k] = '\0';
		}
		description.copy(newDescription1, length, 1);
		string s(newDescription1);
		list.call_insert_front(command, s); 
		i++;                                                                                          
	}
	//list.call_print_list();
	return i;
}

//Executes functions based on the choice from the main menu
template<typename t1, typename t2>
void run_app(List<t1, t2> list)
{
	Profile profiles[100];
	int choice = 0, exit = 0, profileNum = -1, pointTotal = 0;
	while (exit == 0)
	{
		choice = main_menu();
		if (choice == '1')
		{
			cout << "This is a Linux command matching game! Your task is simple. Match the given command with its respective description." << endl << endl
					<< "STEP 1: Set up your PROFILE. You will enter a name to do this." << endl
					<< "STEP 2: Choose the number of commands you want to attempt to match in the game." << endl
					<< "STEP 3: Play the game! The command will be displayed on top of you screen, " << endl
					<< "	with three possible descriptions of the function that command has. " << endl
					<< "	You will be asked to type the number of the description that you think matches the Linux command." << endl
					<< "STEP 4: Update your POINTS! If you give an incorrect match, you will lose a point. " << endl
					<< "	If you give a correct match, you will gain a point. You start with 0 points." << endl << endl
					<< "***NOTE: You can access previous games by selecting the Load Previous Game option. " << endl
					<< "	You also have the ability to add commands to the game or remove them from the game. " << endl
					<< "	Add commands to increase your terminal prowess! GOOD LUCK!!!" << endl << endl;
		}
		else if (choice == '2')
		{
			string playerName;
			int numCommands = 0, listSize = 0;
			cout << "Please enter the player name: ";
			cin >> playerName;
			cout << "How many commands would you like to match? Choose a number from 5 to 30: ";
			cin >> numCommands;
			while (numCommands < 5 || numCommands > 30)
			{
				cout << "Choose a number from 5 to 30: ";
				cin >> numCommands;
			}
			profileNum++; 
			profiles[profileNum].name = playerName;
			profiles[profileNum].points = pointTotal;
			listSize = load_list(listSize, list);
			list.set_number_of_commands(listSize + 1);
			int randomOrder[500];
			int i = 0;
			while (i < numCommands)
			{
				pointTotal = list.call_display_question(pointTotal, randomOrder);
				i++;
			}
			profiles[profileNum].points = pointTotal;
		}
		else if (choice == '3')
		{
			string name;
			cout << "What is the name that was used? ";
			cin >> name;
			for (int i = 0; i < 100; ++i)
			{
				if (profiles[i].name == name)
				{
					cout << "POINTS: " << profiles[i].points << endl;
				}
			}
		}
		else if (choice == '4')
		{
			string commandName;
			string commandDescription;
			cout << "What is the command you would like to add? ";
			cin >> commandName;
			cout << "What is the description that matches that command? ";
			cin >> commandDescription;
			cout << endl;
			list.call_insert_front(commandName, commandDescription);
		}
		else if (choice == '5')
		{
			string commandName;
			cout << "What is the command you would like to remove? ";
			cin >> commandName;
			list.call_remove(commandName);
		}
		else if (choice == '6')
		{
			ofstream outputFile;
			outputFile.open("profiles.csv");
			outputFile << profiles[profileNum].name << " " << profiles[profileNum].points << endl;
			exit = 1;
			list.call_save_commands();
		}
	}
}

//Calls the save_commands function
template <class t1, class t2>
void List<t1, t2>::call_save_commands()
{
	save_commands(pHead);
}

//Write the list of commands to the commands.csv file
template <class t1, class t2>
void List<t1, t2>::save_commands(Node *pHead)
{
	ofstream outputCommands;
	outputCommands.open("commands.csv"); 
	while (pHead != nullptr)
	{
		outputCommands << pHead->command << ",\"" << pHead->description << "\"" << endl;
		pHead = pHead->pNext;
	}
}

//Calls the remove function
template <class t1, class t2>
void List<t1, t2>::call_remove(t1 removeCommand)
{
	remove(&pHead, removeCommand);
}

//Removes a command and descriptions, or an entire node from the list
template <class t1, class t2>
void List<t1, t2>::remove(Node **pHead, t1 removeCommand)
{
	Node *current = *pHead;
	Node *previous;
	if ((*pHead) == nullptr)
	{
		cout << "The list is empty.";
		return;
	}
	if (current->command == removeCommand)
	{
		*pHead = current->pNext;
		free(current);
		return;
	}
	while (current != nullptr && current->command != removeCommand)
	{
		previous = current;
		current = current->pNext;
	}
		previous->pNext = current->pNext;
		free(current);
}

//Calls display_question function
template <class t1, class t2>
int List<t1, t2>::call_display_question(int pointTotal, int randomOrder[])
{
	int points = 0;
	points = display_question(pHead, pointTotal, randomOrder);
	return points;
}

//Calls insert_front function
template <class t1, class t2>
void List<t1, t2>::call_insert_front(t1 newCommand, t2 newDescription)
{
	insert_front(&pHead, newCommand, newDescription);
}

//Calls print_list function
template <class t1, class t2>
void List<t1, t2>::call_print_list()
{
	print_list(pHead); 
}

//Inserts a node with a command and description into the list
template <class t1, class t2>
void List<t1, t2>::insert_front(Node **pHead, t1 newCommand, t2 newDescription)
{
	Node *pMem = new Node;
	if (pMem != nullptr)
	{
		pMem->pNext = nullptr;
		pMem->command = newCommand;
		pMem->description = newDescription;
		if (*pHead != nullptr)
		{
			pMem->pNext = *pHead;
		}
		*pHead = pMem;
	}
}

//Prints the commands and descriptions in the list
template <class t1, class t2>
void List<t1, t2>::print_list(Node *pHead)
{
	while (pHead != nullptr)
	{
		cout << pHead->command << ". " << pHead->description << endl;
		pHead = pHead->pNext;
	}
}

//Displays a question randomly
template<class t1, class t2>
int List<t1, t2>::display_question(Node *pHead, int pointTotal, int randomOrder[])
{
	int points = pointTotal;
	Node *pTemp = pHead;
	int numberOfCommands = get_number_of_commands(), randomCommands = 0, i = 0;
	srand(time(0));
	string correctCommand, correctDescription, randomDescription1, randomDescription2;
	int randomCommand = rand() % numberOfCommands + 1;
	int commandNum = randomCommand;
	while (randomOrder[i] == randomCommand)
	{
		randomCommand = rand() % numberOfCommands + 1;
		commandNum = randomCommand;
		i++;
	}
	randomOrder[randomCommands] = randomCommand;
	randomCommands++;
	int randomDescription1Num = rand() % numberOfCommands + 1;
	int randomDescription2Num = rand() % numberOfCommands + 1;
	while (randomDescription1Num == randomCommand || randomDescription1Num == randomDescription2Num || randomDescription2Num == randomCommand)
	{
		randomDescription1Num = rand() % numberOfCommands + 1;
		randomDescription2Num = rand() % numberOfCommands + 1;
	}

	//correct command
	i = 0;
	while (i < randomCommand - 1)
	{
		pTemp = pTemp->pNext;
		i++;
	}
	correctCommand = pTemp->command;

	//correct description
	pTemp = pHead;
	i = 0;
	while (i < randomCommand - 1)
	{
		pTemp = pTemp->pNext;
		i++;
	}
	correctDescription = pTemp->description;

	//random description 1
	pTemp = pHead;
	i = 0;
	while (i < randomDescription1Num - 1)
	{
		pTemp = pTemp->pNext;
		i++;
	}
	randomDescription1 = pTemp->description;

	//random description 2
	pTemp = pHead;
	i = 0;
	int nullReached = 0;
	while (i < randomDescription2Num - 1)
	{
		if (pTemp->pNext == nullptr)
		{
			randomDescription2 = pTemp->description;
			nullReached = 1;
			i++;
		}
		else {
			pTemp = pTemp->pNext;
			i++;
		}
	}
	if (nullReached == 0)
	{
		randomDescription2 = pTemp->description;
	}

	//gets answer
	int randomOrder1 = rand() % 6 + 1;
	points = get_answer(randomOrder1, correctDescription, correctCommand, randomDescription1, randomDescription2, pointTotal);
	return points;
}
