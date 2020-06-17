//FUNCTION DEFINITIONS

#include "Battleship.h"

int carrierSunkAlready = 0, battleShipSunkAlready = 0, cruiserSunkAlready = 0, submarineSunkAlready = 0, destroyerSunkAlready = 0;

//Runs the game
void run_game()
{
	int startingPlayer = 0;
	int isSunk = 0;
	int isHit = 0;
	int gameOver = 0;
	int sunkShips = 0;
	int manualOrRandom = 0;
	char playerBoard[10][10]; //player 1
	char computerBoard[10][10]; //player 2
	char computerBoardHits[10][10];
	char playerCarrier[5] = { 'c', 'c', 'c', 'c', 'c' };
	char playerBattleship[4] = { 'b', 'b', 'b', 'b' };
	char playerCruiser[3] = { 'r', 'r', 'r' };
	char playerSubmarine[3] = { 's', 's', 's' };
	char playerDestroyer[2] = { 'd', 'd' };
	char compCarrier[5] = { 'c', 'c', 'c', 'c', 'c' };
	char compBattleship[4] = { 'b', 'b', 'b', 'b' };
	char compCruiser[3] = { 'r', 'r', 'r' };
	char compSubmarine[3] = { 's', 's', 's' };
	char compDestroyer[2] = { 'd', 'd' };
	welcome_screen();
	initialize_game_board(playerBoard);
	initialize_game_board(computerBoard);
	initialize_game_board(computerBoardHits);
	startingPlayer = select_starting_player();
	printf("Would you like your ships to be manually or randomly placed on your board? 1 = manual, 2 = random: ");
	scanf("%d", &manualOrRandom);
	if (manualOrRandom == 1)
	{
		manually_place_ships(playerBoard, playerCarrier, playerBattleship, playerCruiser, playerSubmarine, playerDestroyer);
	}
	if (manualOrRandom == 2)
	{
		randomly_place_ships(playerBoard, playerCarrier, playerBattleship, playerCruiser, playerSubmarine, playerDestroyer);
	}
	randomly_place_ships(computerBoard, compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
	//display_board(computerBoard, compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
	
	printf("LET THE GAME BEGIN!!!\n\n\n");
	system("pause");

	if (startingPlayer == 1)
	{
		while (sunkShips != 5)
		{
			system("cls");
			display_board(computerBoardHits, compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
			isHit = player_turn(computerBoard, computerBoardHits, compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
			if (isHit == 1)
			{
				system("cls");
				printf("Yes! You hit an enemy ship!\n\n");		
				display_board(computerBoardHits, compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
				system("pause");
			}
			else {
				system("cls");
				printf("\n\nOops! You missed! \n\n");
				display_board(computerBoardHits, compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
				system("pause");
			}
			sunkShips = check_if_sunk_ship_computer(compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);

			if (sunkShips == 5)
			{
				printf("Player 1 Wins!!!\n\n");
			}

			if (sunkShips != 5)
			{
				system("cls");
				isHit = computer_turn(playerBoard, playerCarrier, playerBattleship, playerCruiser, playerSubmarine, playerDestroyer);
				if (isHit == 1)
				{
					system("cls");
					printf("Oh no! The enemy has hit one of your ships! \n\n");
					display_board(playerBoard, compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
					system("pause");
				}
				else {
					system("cls");
					printf("\n\nYes! The enemy missed!\n\n");
					display_board(playerBoard, compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
					system("pause");
				}
				sunkShips = check_if_sunk_ship_player(playerCarrier, playerBattleship, playerCruiser, playerSubmarine, playerDestroyer);

				if (sunkShips == 5)
				{
					system("cls");
					printf("Player 2 Wins!!!\n\n");
				}
			}
		}
	}

	if (startingPlayer == 2)
	{
		while (sunkShips != 5)
		{
			system("cls");
			isHit = computer_turn(playerBoard, playerCarrier, playerBattleship, playerCruiser, playerSubmarine, playerDestroyer);
			if (isHit == 1)
			{
				system("cls");
				printf("Oh no! The enemy has hit one of your ship! \n\n");
				display_board(playerBoard, compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
				system("pause");
				system("cls");
			}
			else {
				system("cls");
				printf("Yes! The enemy missed!\n\n");
				display_board(playerBoard, compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
				system("pause");
				system("cls");
			}
			sunkShips = check_if_sunk_ship_player(playerCarrier, playerBattleship, playerCruiser, playerSubmarine, playerDestroyer);

			if (sunkShips == 5)
			{
				printf("Player 2 Wins!!!\n\n");
			}

			if (sunkShips != 5)
			{
				system("cls");
				//printf("\n\n");
				display_board(computerBoardHits, compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
				isHit = player_turn(computerBoard, computerBoardHits, compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
				if (isHit == 1)
				{
					system("cls");
					printf("Yes! You hit an enemy ship!\n\n");
					display_board(computerBoardHits, compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
					system("pause");
				}
				else {
					system("cls");
					printf("\n\nOops! You missed! \n\n");
					display_board(computerBoardHits, compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
					system("pause");
				}
				sunkShips = check_if_sunk_ship_computer(compCarrier, compBattleship, compCruiser, compSubmarine, compDestroyer);
				if (sunkShips == 5)
				{
					system("cls");
					printf("Player 1 Wins!!!\n\n");
				}
			}


		}
	}
}

//Displays the welcome screen
void welcome_screen()
{
	printf("                                       ******************************\n");
	printf("                                       || WELCOME TO BATTLESHIP!!! ||\n");
	printf("                                       ******************************\n\n\n");

	printf("                                               )_______(\n");
	printf("                                    ____________/ _____/  ___\n");
	printf("                          ___      / ====================  |      ___ \n");
	printf("      ______      __     [\\\\\\]____/ ______________________ | ___ [///]     __\n");
	printf("      \\     \\____[\\\\]____/ ___________________________________________\ ___[//]______\n");
	printf("       \\ battleship 1049                                                            |\n");
	printf("        \\                                                                          /     \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

	printf("                                         *************************\n");
	printf("                                         ||  RULES OF GAMEPLAY  ||\n");
	printf("                                         *************************\n\n");
	printf("(1) A player will be randomly selected to take the first turn. After that the two players with alternate. Player 1 is you, and Player 2 is the computer.\n");
	printf("(2) You can choose to manually place your ships or have them randomly placed on your board. Ships cannot be placed diagonally. \n");
	printf("(3) You will fire at the enemy's ship by selecting a position on the computer's board to fire at. If you hit a ship, it is a hit. Otherwise, it is a miss.\n");
	printf("(4) You have sunk a ship once you have hit all of the positions that a certain ship covers.\n");
	printf("(5) The ships include 1 carrier (5 units), 1 battleship (4 units), 1 cruiser (3 units), 1 submarine (3 units), and 1 destroyer (2 units). \n");
	printf("(6) Player two will fire at your board. The same rules apply to them. The first player to sink all of the other player's ships wins.\n\n\n");
	system("pause");
	system("cls");
}

//Starts the player's turn
int player_turn(char board[][10], char boardSeen[][10], char carrier[], char battleship[], char cruiser[], char submarine[], char destroyer[])
{
	int row, col, isHit = 0;
	printf("Pick a position to fire at:\n\nRow: ");
	scanf("%d", &row);
	printf("Column: ");
	scanf("%d", &col);
	if (board[row][col] == 'c' || board[row][col] == 'x')
	{
		for (int i = 0; i < 5; ++i)
		{
			if (carrier[i] == board[row][col])
			{
				carrier[i] = 'x';
				break;
			}
		}
		isHit = 1;
		board[row][col] = 'x';
		boardSeen[row][col] = 'x';
	}
	else if (board[row][col] == 'b' || board[row][col] == 'x')
	{
		for (int i = 0; i < 4; ++i)
		{
			if (battleship[i] == board[row][col])
			{
				battleship[i] = 'x';
				break;
			}
		}
		isHit = 1;
		board[row][col] = 'x';
		boardSeen[row][col] = 'x';
	}
	else if (board[row][col] == 'r' || board[row][col] == 'x')
	{
		for (int i = 0; i < 3; ++i)
		{
			if (cruiser[i] == board[row][col])
			{
				cruiser[i] = 'x';
				break;
			}
		}
		isHit = 1;
		board[row][col] = 'x';
		boardSeen[row][col] = 'x';
	}
	else if (board[row][col] == 's' || board[row][col] == 'x')
	{
		for (int i = 0; i < 3; ++i)
		{
			if (submarine[i] == board[row][col])
			{
				submarine[i] = 'x';
				break;
			}
		}
		isHit = 1;
		board[row][col] = 'x';
		boardSeen[row][col] = 'x';
	}
	else if (board[row][col] == 'd' || board[row][col] == 'x')
	{
		for (int i = 0; i < 2; ++i)
		{
			if (destroyer[i] == board[row][col])
			{
				destroyer[i] = 'x';
				break;
			}
		}
		isHit = 1;
		board[row][col] = 'x';
		boardSeen[row][col] = 'x';
		//This is the error
	}
	else {
		board[row][col] = 'm';
		boardSeen[row][col] = 'm';
	}
	return isHit;
}

//Stars the computer's turn
int computer_turn(char board[][10], char carrier[], char battleship[], char cruiser[], char submarine[], char destroyer[])
{
	int row, col, isHit = 0;
	row = rand() % 9;
	col = rand() % 9;
	if (board[row][col] == 'c' || board[row][col] == 'x')
	{
		for (int i = 0; i < 5; ++i)
		{
			if (carrier[i] == board[row][col])
			{
				carrier[i] = 'x';
				break;
			}
		}
		isHit = 1;
		board[row][col] = 'x';
	}
	else if (board[row][col] == 'b' || board[row][col] == 'x')
	{
		for (int i = 0; i < 4; ++i)
		{
			if (battleship[i] == board[row][col])
			{
				battleship[i] = 'x';
				break;
			}
		}
		isHit = 1;
		board[row][col] = 'x';
	}
	else if (board[row][col] == 'r' || board[row][col] == 'x')
	{
		for (int i = 0; i < 3; ++i)
		{
			if (cruiser[i] == board[row][col])
			{
				cruiser[i] = 'x';
				break;
			}
		}
		isHit = 1;
		board[row][col] = 'x';
	}
	else if (board[row][col] == 's' || board[row][col] == 'x')
	{
		for (int i = 0; i < 3; ++i)
		{
			if (submarine[i] == board[row][col])
			{
				submarine[i] = 'x';
				break;
			}
		}
		isHit = 1;
		board[row][col] = 'x';
	}
	else if (board[row][col] == 'd' || board[row][col] == 'x')
	{
		for (int i = 0; i < 2; ++i)
		{
			if (destroyer[i] == board[row][col])
			{
				destroyer[i] = 'x';
				break;
			}
		}
		isHit = 1;
		board[row][col] = 'x';
	}
	else {
		board[row][col] = 'm';
	}
	return isHit;
}

//Checks to see if the computer has a sunken ship
int check_if_sunk_ship_computer(char carrier[], char battleship[], char cruiser[], char submarine[], char destroyer[])
{
	int carrierSunk = 1, battleshipSunk = 1, cruiserSunk = 1, submarineSunk = 1, destroyerSunk = 1;
	int sunkShips = 0;
	carrierSunk = check_carrier_sunk(carrier);
	if (carrierSunk == 1 && carrierSunkAlready == 0)
	{
		carrierSunkAlready = 1;
		printf("Enemy CARRIER has been sunk!\n\n\n");
		system("pause");
	}
	if (carrierSunk == 1)
	{
		sunkShips++;
	}
	battleshipSunk = check_battleship_sunk(battleship);
	if (battleshipSunk == 1 && battleShipSunkAlready == 0)
	{
		battleShipSunkAlready = 1;
		printf("Enemy BATTLESHIP has been sunk!\n\n\n");
		system("pause");
	}
	if (battleshipSunk == 1)
	{
		sunkShips++;
	}
	cruiserSunk = check_cruiser_sunk(cruiser);
	if (cruiserSunk == 1 && cruiserSunkAlready == 0) 
	{
		cruiserSunkAlready = 1;
		printf("Enemy CRUISER has been sunk!\n\n\n");
		system("pause");
	}
	if (cruiserSunk == 1)
	{
		sunkShips++;
	}
	submarineSunk = check_cruiser_sunk(submarine);
	if (submarineSunk == 1 && submarineSunkAlready == 0)
	{
		submarineSunkAlready = 1;
		printf("Enemy SUBMARINE has been sunk!\n\n\n");
		system("pause");
	}
	if (submarineSunk == 1)
	{
		sunkShips++;
	}
	destroyerSunk = check_destroyer_sunk(destroyer);
	if (destroyerSunk == 1 && destroyerSunkAlready == 0)
	{
		destroyerSunkAlready = 1;
		printf("Enemy DESTROYER has been sunk!\n\n\n");
		system("pause");
	}
	if (destroyerSunk == 1)
	{
		sunkShips++;
	}
	return sunkShips; 
}

//Check to see if the player has a sunken ship
int check_if_sunk_ship_player(char carrier[], char battleship[], char cruiser[], char submarine[], char destroyer[])
{
	int carrierSunk = 1, battleshipSunk = 1, cruiserSunk = 1, submarineSunk = 1, destroyerSunk = 1;
	int sunkShips = 0;
	carrierSunk = check_carrier_sunk(carrier);
	if (carrierSunk == 1)
	{
		printf("YOUR CARRIER HAS BEEN SUNK!\n");
		sunkShips++;
	}
	battleshipSunk = check_battleship_sunk(battleship);
	if (battleshipSunk == 1)
	{
		printf("YOUR BATTLESIHP HAS BEEN SUNK!\n");
		sunkShips++;
	}
	cruiserSunk = check_cruiser_sunk(cruiser);
	if (cruiserSunk == 1)
	{
		printf("YOUR CRUISER HAS BEEN SUNK!\n");
		sunkShips++;
	}
	submarineSunk = check_cruiser_sunk(submarine);
	if (submarineSunk == 1)
	{
		printf("YOUR SUBMARINE HAS BEEN SUNK!\n");
		sunkShips++;
	}
	destroyerSunk = check_destroyer_sunk(destroyer);
	if (destroyerSunk == 1)
	{
		printf("YOUR DESTROYER HAS BEEN SUNK!\n");
		sunkShips++;
	}
	if (sunkShips >= 1)
	{
		printf("\n\n\n\n\n");
		system("pause");
	}
	return sunkShips;
}

//Checks if the carrier has been sunk
int check_carrier_sunk(char ship[])
{
	int isSunk = 1;
	for (int i = 0; i < 5; ++i)
	{
		if (ship[i] != 'x')
		{
			isSunk = 0;
		}
	}
	return isSunk;
}

//Checks if the battleship has been sunk
int check_battleship_sunk(char ship[])
{
	int isSunk = 1;
	for (int i = 0; i < 4; ++i)
	{
		if (ship[i] != 'x')
		{
			isSunk = 0;
		}
	}
	return isSunk;
}

//Checks if the cruiser has been sunk
int check_cruiser_sunk(char ship[])
{
	int isSunk = 1;
	for (int i = 0; i < 3; ++i)
	{
		if (ship[i] != 'x')
		{
			isSunk = 0;
		}
	}
	return isSunk;
}

//Checks if the destroyer has been sunk
int check_destroyer_sunk(char ship[])
{
	int isSunk = 1;
	for (int i = 0; i < 2; ++i)
	{
		if (ship[i] != 'x')
		{
			isSunk = 0;
		}
	}
	return isSunk;
}

//Initializes the game board
void initialize_game_board(char board[][10])
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			board[i][j] = '-';
		}
	}

}

//Selects a starting player
int select_starting_player()
{
	srand(time(NULL));
	int startingPlayer = rand() % 2 + 1;
	printf("Player %d starts!\n\n", startingPlayer);
	system("pause");
	system("cls");
	return startingPlayer;
}

//Manually places ships on the board
void manually_place_ships(char board[][10], char carrier[], char battleship[], char cruiser[], char submarine[], char destroyer[])
{
	int startingRow, startingColumn, direction, placementError = 1;

	while (placementError == 1)
	{
		display_board(board, carrier, battleship, cruiser, submarine, destroyer);
		printf("PLACE YOUR CARRIER\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("Starting row: ");
		scanf("%d", &startingRow);
		printf("Starting column: ");
		scanf("%d", &startingColumn);
		printf("Direction (1 = left, 2 = right, 3 = up, 4 = down): ");
		scanf("%d", &direction);
		placementError = check_placement_carrier(board, startingRow, startingColumn, direction);
		if (placementError == 1)
		{
			system("cls");
			printf("Oops! That space isn't available! Please choose again! \n\n");
			display_board(board, carrier, battleship, cruiser, submarine, destroyer);
		}
		else if (placementError == 0)
		{
			place_carrier(board, startingRow, startingColumn, direction, carrier);
			printf("Placement of CARRIER was successful!!!\n\n");
			system("pause");
			system("cls");
			display_board(board, carrier, battleship, cruiser, submarine, destroyer);
		}
	}

	placementError = 1;
	while(placementError == 1)
	{
		printf("PLACE YOUR BATTLESHIP\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("Starting row: ");
		scanf("%d", &startingRow);
		printf("Starting column: ");
		scanf("%d", &startingColumn);
		printf("Direction (1 = left, 2 = right, 3 = up, 4 = down): ");
		scanf("%d", &direction);
		placementError = check_placement_battleship(board, startingRow, startingColumn, direction);
		if (placementError == 1)
		{
			system("cls");
			printf("Oops! That space isn't available! Please choose again! \n\n");
			display_board(board, carrier, battleship, cruiser, submarine, destroyer);
		}
		else if(placementError == 0)
		{ 
			place_battleship(board, startingRow, startingColumn, direction, battleship);
			printf("Placement of BATTLESHIP was successful!!!\n\n");
			system("pause");
			system("cls");
			display_board(board, carrier, battleship, cruiser, submarine, destroyer);
		}
	}

	placementError = 1;
	while (placementError == 1)
	{
		printf("PLACE YOUR CRUISER\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("Starting row: ");
		scanf("%d", &startingRow);
		printf("Starting column: ");
		scanf("%d", &startingColumn);
		printf("Direction (1 = left, 2 = right, 3 = up, 4 = down): ");
		scanf("%d", &direction);
		placementError = check_placement_cruiser(board, startingRow, startingColumn, direction);
		if (placementError == 1)
		{
			system("cls");
			printf("Oops! That space isn't available! Please choose again! \n\n");
			display_board(board, carrier, battleship, cruiser, submarine, destroyer);
		}
		else if (placementError == 0)
		{
			place_cruiser(board, startingRow, startingColumn, direction, cruiser);
			printf("Placement of CRUISER was successful!!!\n\n");
			system("pause");
			system("cls");
			display_board(board, carrier, battleship, cruiser, submarine, destroyer);
		}
	}

	placementError = 1;
	while (placementError == 1)
	{
		printf("PLACE YOUR SUBMARINE\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("Starting row: ");
		scanf("%d", &startingRow);
		printf("Starting column: ");
		scanf("%d", &startingColumn);
		printf("Direction (1 = left, 2 = right, 3 = up, 4 = down): ");
		scanf("%d", &direction);
		placementError = check_placement_cruiser(board, startingRow, startingColumn, direction);
		if (placementError == 1)
		{	
			system("cls");
			printf("Oops! That space isn't available! Please choose again! \n\n");
			display_board(board, carrier, battleship, cruiser, submarine, destroyer);
		}
		else if (placementError == 0)
		{
			place_cruiser(board, startingRow, startingColumn, direction, submarine);
			printf("Placement of SUBMARINE was successful!!!\n\n");
			system("pause");
			system("cls");
			display_board(board, carrier, battleship, cruiser, submarine, destroyer);
		}
	}

	placementError = 1;
	while (placementError == 1)
	{
		printf("PLACE YOUR DESTROYER\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("Starting row: ");
		scanf("%d", &startingRow);
		printf("Starting column: ");
		scanf("%d", &startingColumn);
		printf("Direction (1 = left, 2 = right, 3 = up, 4 = down): ");
		scanf("%d", &direction);
		placementError = check_placement_destroyer(board, startingRow, startingColumn, direction);
		if (placementError == 1)
		{
			system("cls");
			printf("Oops! That space isn't available! Please choose again! \n\n");
			display_board(board, carrier, battleship, cruiser, submarine, destroyer);
		}
		else if (placementError == 0)
		{
			place_destroyer(board, startingRow, startingColumn, direction, destroyer);
			printf("Placement of DESTROYER was successful!!!\n\n");
			system("pause");
			system("cls");
			display_board(board, carrier, battleship, cruiser, submarine, destroyer);
		}
	}
}

//Randomly places ships on a board
void randomly_place_ships(char board[][10], char carrier[], char battleship[], char cruiser[], char submarine[], char destroyer[])
{
	int startingRow, startingColumn, direction, placementError = 1;

	while (placementError == 1)
	{	
		startingRow = rand() % 9;
		startingColumn = rand() % 9;
		direction = rand() % 4 + 1;
		placementError = check_placement_carrier(board, startingRow, startingColumn, direction);
		if (placementError == 0)
		{
			place_carrier(board, startingRow, startingColumn, direction, carrier);
		}
	}

	placementError = 1;
	while (placementError == 1)
	{
		startingRow = rand() % 9;
		startingColumn = rand() % 9;
		direction = rand() % 4 + 1;
		placementError = check_placement_battleship(board, startingRow, startingColumn, direction);
		if (placementError == 0)
		{
			place_battleship(board, startingRow, startingColumn, direction, battleship);
		}
	}

	placementError = 1;
	while (placementError == 1)
	{
		startingRow = rand() % 9;
		startingColumn = rand() % 9;
		direction = rand() % 4 + 1;
		placementError = check_placement_cruiser(board, startingRow, startingColumn, direction);
		if (placementError == 0)
		{
			place_cruiser(board, startingRow, startingColumn, direction, cruiser);
		}
	}

	placementError = 1;
	while (placementError == 1)
	{
		startingRow = rand() % 9;
		startingColumn = rand() % 9;
		direction = rand() % 4 + 1;
		placementError = check_placement_cruiser(board, startingRow, startingColumn, direction);
		if (placementError == 0)
		{
			place_cruiser(board, startingRow, startingColumn, direction, submarine);
		}
	}

	placementError = 1;
	while (placementError == 1)
	{
		startingRow = rand() % 9;
		startingColumn = rand() % 9;
		direction = rand() % 4 + 1;
		placementError = check_placement_destroyer(board, startingRow, startingColumn, direction);
		if (placementError == 0)
		{
			place_destroyer(board, startingRow, startingColumn, direction, destroyer);
		}
	}
}

//Checks for an error in cruiser placement
int check_placement_carrier(char board[][10], int row, int col, int dir)
{
	int error = 0;
	if (dir == 1)
	{
		if (col >= 3)
		{
			error = 0;
		}
		else {
			error = 1;
		}
	}
	else if (dir == 2)
	{
		if (col <= 6)
		{
			error = 0;
		}
		else {
			error = 1;
		}
	}
	else if (dir == 3)
	{
		if (row >= 3)
		{
			error = 0;
		}
		else {
			error = 1;
		}
	}
	else if (dir == 4)
	{
		if (row <= 6)
		{
			error = 0;
		}
		else {
			error = 1;
		}
	}
	return error;
}

//Checks for an error in battleship placement
int check_placement_battleship(char board[][10], int row, int col, int dir)
{
	int error = 0;
	if (dir == 1)
	{
		if (col >= 3)
		{
			if (board[row][col] == '-' && board[row][col - 1] == '-' && board[row][col - 2] == '-' && board[row][col - 3] == '-')
			{
				error = 0;
			}
			else {
				error = 1;
			}
		}
		else {
			error = 1;
		}
	}
	else if (dir == 2)
	{
		if (col <= 6)
		{
			if (board[row][col] == '-' && board[row][col + 1] == '-' && board[row][col + 2] == '-' && board[row][col + 3] == '-')
			{
				error = 0;
			}
			else {
				error = 1;
			}
		}
		else {
			error = 1;
		}
	}
	else if (dir == 3)
	{
		if (row >= 3)
		{
			if (board[row][col] == '-' && board[row - 1][col] == '-' && board[row - 2][col] == '-' && board[row - 3][col] == '-')
			{
				error = 0;
			}
			else {
				error = 1;
			}
		}
		else {
			error = 1;
		}	
	}
	else if (dir == 4)
	{
		if (row <= 6)
		{
			if (board[row][col] == '-' && board[row + 1][col] == '-' && board[row + 2][col] == '-' && board[row + 3][col] == '-')
			{
				error = 0;
			}
			else {
				error = 1;
			}
		}
		else {
			error = 1;
		}
	}
	return error;
}

//Checks for an error in cruiser placement
int check_placement_cruiser(char board[][10], int row, int col, int dir)
{
	int error = 0;
	if (dir == 1)
	{
		if (col >= 2)
		{
			if (board[row][col] == '-' && board[row][col - 1] == '-' && board[row][col - 2] == '-')
			{
				error = 0;
			}
			else {
				error = 1;
			}
		}
		else {
			error = 1;
		}
	}
	else if (dir == 2)
	{
		if (col <= 7)
		{
			if (board[row][col] == '-' && board[row][col + 1] == '-' && board[row][col + 2] == '-')
			{
				error = 0;
			}
			else {
				error = 1;
			}
		}
		else {
			error = 1;
		}
	}
	else if (dir == 3)
	{
		if (row >= 2)
		{
			if (board[row][col] == '-' && board[row - 1][col] == '-' && board[row - 2][col] == '-')
			{
				error = 0;
			}
			else {
				error = 1;
			}
		}
		else {
			error = 1;
		}
	}
	else if (dir == 4)
	{
		if (row <= 7)
		{
			if (board[row][col] == '-' && board[row + 1][col] == '-' && board[row + 2][col] == '-')
			{
				error = 0;
			}
			else {
				error = 1;
			}
		}
		else {
			error = 1;
		}
	}
	return error;
}

//Checks for an error in destroyer placement
int check_placement_destroyer(char board[][10], int row, int col, int dir)
{
	int error = 0;
	if (dir == 1)
	{
		if (col >= 1)
		{
			if (board[row][col] == '-' && board[row][col - 1] == '-')
			{
				error = 0;
			}
			else {
				error = 1;
			}
		}
		else {
			error = 1;
		}
	}
	else if (dir == 2)
	{
		if (col <= 8)
		{
			if (board[row][col] == '-' && board[row][col + 1] == '-')
			{
				error = 0;
			}
			else {
				error = 1;
			}
		}
		else {
			error = 1;
		}
	}
	else if (dir == 3)
	{
		if (row >= 1)
		{
			if (board[row][col] == '-' && board[row - 1][col] == '-')
			{
				error = 0;
			}
			else {
				error = 1;
			}
		}
		else {
			error = 1;
		}
	}
	else if (dir == 4)
	{
		if (row <= 8)
		{
			if (board[row][col] == '-' && board[row + 1][col] == '-')
			{
				error = 0;
			}
			else {
				error = 1;
			}
		}
		else {
			error = 1;
		}
	}
	return error;
}

//Places the carrier
void place_carrier(char board[][10], int row, int col, int dir, char ship[])
{
	board[row][col] = ship[0];
	if (dir == 1)
	{
		board[row][col - 1] = ship[1];
		board[row][col - 2] = ship[2];
		board[row][col - 3] = ship[3];
		board[row][col - 4] = ship[4];
	}
	else if (dir == 2)
	{
		board[row][col + 1] = ship[1];
		board[row][col + 2] = ship[2];
		board[row][col + 3] = ship[3];
		board[row][col + 4] = ship[4];
	}
	else if (dir == 3)
	{
		board[row - 1][col] = ship[1];
		board[row - 2][col] = ship[2];
		board[row - 3][col] = ship[3];
		board[row - 4][col] = ship[4];
	}
	else if (dir == 4)
	{
		board[row + 1][col] = ship[1];
		board[row + 2][col] = ship[2];
		board[row + 3][col] = ship[3];
		board[row + 4][col] = ship[4];
	}
}

//Places the battleship
void place_battleship(char board[][10], int row, int col, int dir, char ship[])
{
	board[row][col] = ship[0];
	if (dir == 1)
	{
		board[row][col - 1] = ship[1];
		board[row][col - 2] = ship[2];
		board[row][col - 3] = ship[3];
	}
	else if (dir == 2)
	{
		board[row][col + 1] = ship[1];
		board[row][col + 2] = ship[2];
		board[row][col + 3] = ship[3];
	}
	else if (dir == 3)
	{
		board[row - 1][col] = ship[1];
		board[row - 2][col] = ship[2];
		board[row - 3][col] = ship[3];
	}
	else if (dir == 4)
	{
		board[row + 1][col] = ship[1];
		board[row + 2][col] = ship[2];
		board[row + 3][col] = ship[3];
	}
}

//Places the cruiser
void place_cruiser(char board[][10], int row, int col, int dir, char ship[])
{
	board[row][col] = ship[0];
	if (dir == 1)
	{
		board[row][col - 1] = ship[1];
		board[row][col - 2] = ship[2];
	}
	else if (dir == 2)
	{
		board[row][col + 1] = ship[1];
		board[row][col + 2] = ship[2];
	}
	else if (dir == 3)
	{
		board[row - 1][col] = ship[1];
		board[row - 2][col] = ship[2];
	}
	else if (dir == 4)
	{
		board[row + 1][col] = ship[1];
		board[row + 2][col] = ship[2];
	}
}

//Places the destroyer
void place_destroyer(char board[][10], int row, int col, int dir, char ship[])
{
	board[row][col] = ship[0];
	if (dir == 1)
	{
		board[row][col - 1] = ship[1];
	}
	else if (dir == 2)
	{
		board[row][col + 1] = ship[1];
	}
	else if (dir == 3)
	{
		board[row - 1][col] = ship[1];
	}
	else if (dir == 4)
	{
		board[row + 1][col] = ship[1];
	}
}

//Displays a board
void display_board(char board[][10], char carrier[], char battleship[], char cruiser[], char submarine[], char destroyer[])
{
	int positionMarkers[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	printf("     %d   %d   %d   %d   %d   %d   %d   %d   %d   %d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	
	printf("\n");
	for (int j = 0; j < 10; ++j)
	{
		printf("%d   ", positionMarkers[j]);
		for (int k = 0; k < 10; ++k)
		{
			printf(" %c  ", board[j][k]);
		}
		printf("\n\n");
	}
}