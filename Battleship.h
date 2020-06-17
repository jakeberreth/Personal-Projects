#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

//FUNCTION PROTOTYPES

void run_game();
void welcome_screen();
void initialize_game_board(char board[][10]);
int select_starting_player();
void manually_place_ships(char board[][10], char carrier[], char battleship[], char cruiser[], char submarine[], char destroyer[]);
void display_board(char board[][10], char carrier[], char battleship[], char cruiser[], char submarine[], char destroyer[]);
int check_placement_battleship(char board[][10], int row, int col, int dir);
int check_placement_cruiser(char board[][10], int row, int col, int dir);
int check_placement_destroyer(char board[][10], int row, int col, int dir);
void place_carrier(char board[][10], int row, int col, int dir, char ship[]);
void place_battleship(char board[][10], int row, int col, int dir, char ship[]);
void place_cruiser(char board[][10], int row, int col, int dir, char ship[]);
void place_destroyer(char board[][10], int row, int col, int dir, char ship[]);
void randomly_place_ships(char board[][10], char carrier[], char battleship[], char cruiser[], char submarine[], char destroyer[]);
int check_carrier_sunk(char ship[]);
int check_battleship_sunk(char battleship[]);
int check_cruiser_sunk(char cruiser[]);
int check_destroyer_sunk(char destroyer[]);
int check_if_sunk_ship_computer(char carrier[], char battleship[], char cruiser[], char submarine[], char destroyer[]);
int check_if_sunk_ship_player(char carrier[], char battleship[], char cruiser[], char submarine[], char destroyer[]);
int player_turn(char board[][10], char carrier[], char battleship[], char cruiser[], char submarine[], char destroyer[]);
int computer_turn(char board[][10], char carrier[], char battleship[], char cruiser[], char submarine[], char destroyer[]);
int check_placement_carrier(char board[][10], int row, int col, int dir);

