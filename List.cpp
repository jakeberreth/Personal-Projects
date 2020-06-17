#include "List.h

//Displays the main menu
int main_menu()
{
	char option = 0;
	cout << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n5. Remove Command\n6. Exit\n\n";
	cout << "Please choose an option: ";
	cin >> option;
	while (option != '1' && option != '2' && option != '3' && option != '4' && option != '5' && option != '6')
	{
		system("cls");
		cout << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n5. Remove Command\n6. Exit\n\n";
		cout << "Please choose an option that corresponds with the number of an option: ";
		cin >> option;
	}
	return option;
}

//Gets an answer to a question
int get_answer(int randomOrder, string correctDescription, string correctCommand, string randomDescription1, string randomDescription2, int pointTotal)
{
	int answer = 0, correctAnswer = 0, points = pointTotal;
	if (randomOrder == 1)
	{
		cout << "Command: " << correctCommand << "\n\n" << "1. " << randomDescription1 << "\n2. " << randomDescription2 << "\n3. " << correctDescription << "\n\n";
		cout << "Enter the number corresponding to your answer: ";
		cin >> answer;
		cout << "\n\n";
		correctAnswer = 3;
		if (answer != correctAnswer)
		{
			cout << "Incorrect! " << correctCommand << " -" << correctDescription << "You have lost 1 point. Your point total is " << --points << "\n";
			cout << endl;
		}
		else if (answer == correctAnswer)
		{
			cout << "Correct! " << correctCommand << " -" << correctDescription << "You have gained 1 point. Your point total is " << ++points << "\n";
			cout << endl;
		}
	}
	else if (randomOrder == 2)
	{
		cout << "Command: " << correctCommand << "\n\n" << "1. " << randomDescription2 << "\n2. " << randomDescription1 << "\n3. " << correctDescription << "\n\n";
		cout << "Enter the number corresponding to your answer: ";
		cin >> answer;
		correctAnswer = 3;
		if (answer != correctAnswer)
		{
			cout << "Incorrect! " << correctCommand << " -" << correctDescription << "You have lost 1 point. Your point total is " << --points << "\n";
			cout << endl;
		}
		else if (answer == correctAnswer)
		{
			cout << "Correct! " << correctCommand << " -" << correctDescription << "You have gained 1 point. Your point total is " << ++points << "\n";
			cout << endl;
		}
	}
	else if (randomOrder == 3)
	{
		cout << "Command: " << correctCommand << "\n\n" << "1. " << correctDescription << "\n2. " << randomDescription2 << "\n3. " << randomDescription1 << "\n\n";
		cout << "Enter the number corresponding to your answer: ";
		cin >> answer;
		correctAnswer = 1;
		if (answer != correctAnswer)
		{
			cout << "Incorrect! " << correctCommand << " -" << correctDescription << "You have lost 1 point. Your point total is " << --points << "\n";
			cout << endl;
		}
		else if (answer == correctAnswer)
		{
			cout << "Correct! " << correctCommand << " -" << correctDescription << "You have gained 1 point. Your point total is " << ++points << "\n";
			cout << endl;
		}
	}
	else if (randomOrder == 4)
	{
		cout << "Command: " << correctCommand << "\n\n" << "1. " << correctDescription << "\n2. " << randomDescription1 << "\n3. " << randomDescription2 << "\n\n";
		cout << "Enter the number corresponding to your answer: ";
		cin >> answer;
		correctAnswer = 1;
		if (answer != correctAnswer)
		{
			cout << "Incorrect! " << correctCommand << " -" << correctDescription << "You have lost 1 point. Your point total is " << --points << "\n";
			cout << endl;
		}
		else if (answer == correctAnswer)
		{
			cout << "Correct! " << correctCommand << " -" << correctDescription << "You have gained 1 point. Your point total is " << ++points << "\n";
			cout << endl;
		}
	}
	else if (randomOrder == 5)
	{
		cout << "Command: " << correctCommand << "\n\n" << "1. " << randomDescription1 << "\n2. " << correctDescription << "\n3. " << randomDescription2 << "\n\n";
		cout << "Enter the number corresponding to your answer: ";
		cin >> answer;
		correctAnswer = 2;
		if (answer != correctAnswer)
		{
			cout << "Incorrect! " << correctCommand << " -" << correctDescription << "You have lost 1 point. Your point total is " << --points << "\n";
			cout << endl;
		}
		else if (answer == correctAnswer)
		{
			cout << "Correct! " << correctCommand << " -" << correctDescription << "You have gained 1 point. Your point total is " << ++points << "\n";
			cout << endl;
		}
	}
	else if (randomOrder == 6)
	{
		cout << "Command: " << correctCommand << "\n\n" << "1. " << randomDescription2 << "\n2. " << correctDescription << "\n3 ." << randomDescription1 << "\n\n";
		cout << "Enter the number corresponding to your answer: ";
		cin >> answer;
		correctAnswer = 2;
		if (answer != correctAnswer)
		{
			cout << "Incorrect! " << correctCommand << " -" << correctDescription << "You have lost 1 point. Your point total is " << --points << "\n";
			cout << endl;
		}
		else if (answer == correctAnswer)
		{
			cout << "Correct! " << correctCommand << " -" << correctDescription << "You have gained 1 point. Your point total is " << ++points << "\n";
			cout << endl;
		}
	}
	return points;
}

//I needed to put ++ and -- in front of points to get this to work properly, ++points is very different from points++.