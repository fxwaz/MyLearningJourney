// Project 01 - Rock Paper Scissors Game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enGameOptions { Stone = 1, Paper, Scissor };
enum WhoWon { PlayerWon = 1, ComputerWon, NobodyWon};
enum ContinueOrCloseGame { ContinueGame = 1, CloseGame};



// Helper functions
string WhoIsTheWinner(int PlayerWon, int ComputerWon)
{
	if (PlayerWon > ComputerWon)
		return "Player";
	else if (ComputerWon > PlayerWon)
		return "Computer";
	else
		return "NoBody";
}

string ConvertNumbersToNames(int UserNumber)
{
	if (UserNumber == 1)
		return "Stone";
	else if (UserNumber == 2)
		return "Paper";
	else
		return "Scissor";
}

enGameOptions UserOption(int UserNumber)
{

	switch (UserNumber)
	{
	case 1:
		return enGameOptions::Stone;
	case 2:
		return enGameOptions::Paper;
	case 3:
		return enGameOptions::Scissor;
	}

}

int RandomNumber(int From, int To)
{
	int RandomNumber = rand() % (To - From + 1) + From;

	return RandomNumber;
}

int ReadNumberInRange(string Message, int From, int To)
{
	int UserNumber;

	do
	{
		cout << Message;
		cin >> UserNumber;

		if (UserNumber < From || UserNumber > To)
			cout << "You have to chose only from " << From << " To " << To << " !\n";

	} while (UserNumber < From || UserNumber > To);

	return UserNumber;
}



// Game functions
int HowManyRounds()
{
	int HowManyRounds = ReadNumberInRange("\nPlease enter how many rounds u want to play : ", 1, 100);

	return HowManyRounds;
}

int UserChoice()
{
	int UserChoice;

	cout << "\nYour Choice : [1] Stone , [2] Paper , [3] Scissors : ";

	UserChoice = ReadNumberInRange("", 1, 3);

	return UserChoice;

}

int ComputerChoice()
{
	return RandomNumber(1, 3);
}

WhoWon WhoWonPlayerOrComputer(int UserChoice, int ComputerChoice)
{
	enGameOptions userChoice = UserOption(UserChoice);
	enGameOptions computerChoice = UserOption(ComputerChoice);

	if (userChoice == enGameOptions::Stone && computerChoice == enGameOptions::Paper)
	{
		return WhoWon::ComputerWon;
	}
	else if (userChoice == enGameOptions::Paper && computerChoice == enGameOptions::Stone)
	{
		return WhoWon::PlayerWon;
	}
	// Stone and scissor
	else if (userChoice == enGameOptions::Stone && computerChoice == enGameOptions::Scissor)
	{
		return WhoWon::PlayerWon;
	}
	else if (userChoice == enGameOptions::Scissor && computerChoice == enGameOptions::Stone)
	{
		return WhoWon::ComputerWon;
	}
	// Scissor and paper
	else if (userChoice == enGameOptions::Scissor && computerChoice == enGameOptions::Paper)
	{
		return WhoWon::PlayerWon;
	}
	else if (userChoice == enGameOptions::Paper && computerChoice == enGameOptions::Scissor)
	{
		return WhoWon::ComputerWon;
	}
	// Draw
	else if (userChoice == enGameOptions::Paper && computerChoice == enGameOptions::Paper)
	{
		return WhoWon::NobodyWon;
	}
	else if (userChoice == enGameOptions::Stone && computerChoice == enGameOptions::Stone)
	{
		return WhoWon::NobodyWon;
	}
	else if (userChoice == enGameOptions::Scissor && computerChoice == enGameOptions::Scissor)
	{
		return WhoWon::NobodyWon;
	}
}

void RoundDetails(int RoundCount, int UserChoice, int ComputerChoice, int &HowManyWinPlayer, int &HowManywinComp, int &draw)
{
	WhoWon RoundWinner = WhoWonPlayerOrComputer(UserChoice, ComputerChoice);

	if (RoundWinner == WhoWon::PlayerWon)
	{
		system("color 2F");
		cout << "\n------------------------- Round [" << RoundCount << "] -------------------------" << endl;
		cout << "Player1 Choice : " << ConvertNumbersToNames(UserChoice) << endl;
		cout << "Computer Choice : " << ConvertNumbersToNames(ComputerChoice) << endl;
		cout << "Round Winner : [Player] " << endl;
		cout << "-------------------------------------------------------------" << endl;
		HowManyWinPlayer++;
	}
	else if (RoundWinner == WhoWon::ComputerWon)
	{
		system("color 4F");
		cout << "\n------------------------- Round [" << RoundCount << "] -------------------------" << endl;
		cout << "Player1 Choice : " << ConvertNumbersToNames(UserChoice) << endl;
		cout << "Computer Choice : " << ConvertNumbersToNames(ComputerChoice) << endl;
		cout << "Round Winner : [Computer] " << endl;
		cout << "-------------------------------------------------------------" << endl;
		HowManywinComp++;
	}
	else
	{
		system("color 8F");
		cout << "\n------------------------- Round [" << RoundCount << "] -------------------------" << endl;
		cout << "Player1 Choice : " << ConvertNumbersToNames(UserChoice) << endl;
		cout << "Computer Choice : " << ConvertNumbersToNames(ComputerChoice) << endl;
		cout << "Round Winner : [NoBody] " << endl;
		cout << "-------------------------------------------------------------" << endl;
		draw++;
	}


}

void LoopForRounds(int Howmanyrounds, int& HowManyWinPlayer, int& HowManywinComp, int& draw)
{
	for (int i = 1; i <= Howmanyrounds; i++)
	{
		cout << "\nRound [" << i << "] Begins : " << endl;

		int userChoice = UserChoice();
		int computerChoice = ComputerChoice();
		RoundDetails(i, userChoice, computerChoice, HowManyWinPlayer, HowManywinComp, draw);
	}
}

void FinalResult(int RoundCount, int HowManyPlayerWon, int HowManyComputerWon, int HowManyDraw)
{
	cout << "\t\t\t\t\t---------------------------------------------------" << endl;
	cout << "\t\t\t\t\t                    Game Over                      " << endl;
	cout << "\t\t\t\t\t---------------------------------------------------" << endl;
	cout << "\t\t\t\t\t         +++++++++ Game Result ++++++++		      " << endl;
	cout << "\t\t\t\t\t---------------------------------------------------" << endl;
	cout << "\t\t\t\t\tGame Rounds : " << RoundCount << "                 " << endl;
	cout << "\t\t\t\t\tPlayer won times : " << HowManyPlayerWon << "      " << endl;
	cout << "\t\t\t\t\tComputer won times : " << HowManyComputerWon << "  " << endl;
	cout << "\t\t\t\t\tDraw times : " << HowManyDraw << "                 " << endl;
	cout << "\t\t\t\t\tFinal Winner : " << WhoIsTheWinner(HowManyPlayerWon, HowManyComputerWon) << endl;
}

char DoYouWantToContinue()
{
	char WannaContinue;

	do
	{
		cout << "\n\t\t\t\t\tDo u want to continue play ? [Y] Yes , [N] No : ";
		cin >> WannaContinue;

	} while (WannaContinue != 'y' && WannaContinue != 'Y' && WannaContinue != 'n' && WannaContinue != 'N');


	return WannaContinue;
}

ContinueOrCloseGame ReGameOrClose(char YesOrNo)
{
	if (YesOrNo == 'y' || YesOrNo == 'Y')
		return ContinueOrCloseGame::ContinueGame;
	else
		return ContinueOrCloseGame::CloseGame;
}

void FinalGame()
{


	do
	{
		int Howmanyrounds = HowManyRounds();
		int HowManyPlayerWon = 0;
		int HowManyComputerWon = 0;
		int HowManyDraw = 0;

		LoopForRounds(Howmanyrounds, HowManyPlayerWon, HowManyComputerWon, HowManyDraw);
		FinalResult(Howmanyrounds, HowManyPlayerWon, HowManyComputerWon, HowManyDraw);

	} while (ReGameOrClose(DoYouWantToContinue()) == ContinueOrCloseGame::ContinueGame);


}



int main()
{
	srand((unsigned)time(NULL));

	FinalGame();

	cout << "\t\t\t\t\t\t\t\tBy waz.";
}