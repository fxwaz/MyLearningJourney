// Project 01 - Rock Paper Scissors Game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



enum enGameOptions { Stone = 1, Paper, Scissor };
enum WhoWon { PlayerWon = 1, ComputerWon, NobodyWon};
enum ContinueOrCloseGame { ContinueGame = 1, CloseGame};

struct stRoundInfo
{
	int RoundNumber;
	enGameOptions UserChoice;
	enGameOptions ComputerChoice;
	WhoWon RoundWinner;
};

struct stGameInfo
{
	int HowManyRounds = 0;
	int HowManyPlayerWon = 0;
	int HowManyComputerWon = 0;
	int HowManyDraw = 0;
	WhoWon GameWinner;
};



// Helper functions
string Tabs(int NumberOfTabs)
{
	string Tab = "";

	for (int i = 1; i <= NumberOfTabs; i++)
	{
		Tab = Tab + "\t";
	}

	return Tab;
}

WhoWon WhoIsTheWinner(stGameInfo PlayerVsComp)
{
	if (PlayerVsComp.HowManyPlayerWon > PlayerVsComp.HowManyComputerWon)
		return WhoWon::PlayerWon;
	else if (PlayerVsComp.HowManyComputerWon > PlayerVsComp.HowManyPlayerWon)
		return WhoWon::ComputerWon;
	else
		return WhoWon::NobodyWon;
}

string ConverChoiceToName(enGameOptions UserChoice)
{
	if (UserChoice == enGameOptions::Stone)
		return "Stone";
	else if (UserChoice == enGameOptions::Paper)
		return "Paper";
	else
		return "Scissor";
}

string ConvertWinnerToName(WhoWon WinnerName)
{
	if (WinnerName == WhoWon::PlayerWon)
		return "Player";
	else if (WinnerName == WhoWon::ComputerWon)
		return "Computer";
	else
		return "Nobody";
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
int ReadHowManyRounds()
{
	int HowManyRounds = ReadNumberInRange("Please enter how many rounds u want to play : ", 1, 100);

	return HowManyRounds;
}

enGameOptions UserChoice()
{
	int UserChoice;

	cout << "\nYour Choice : [1] Stone , [2] Paper , [3] Scissors : ";

	UserChoice = ReadNumberInRange("", 1, 3);

	return enGameOptions(UserChoice);

}

enGameOptions ComputerChoice()
{
	return enGameOptions(RandomNumber(1, 3));
}

WhoWon WhoWonPlayerOrComputer(stRoundInfo RoundInfo)
{
	
	if (RoundInfo.UserChoice == RoundInfo.ComputerChoice)
		return WhoWon::NobodyWon;

	if (RoundInfo.UserChoice == enGameOptions::Stone && RoundInfo.ComputerChoice == enGameOptions::Paper)
		return WhoWon::ComputerWon;

	if (RoundInfo.UserChoice == enGameOptions::Scissor && RoundInfo.ComputerChoice == enGameOptions::Stone)
		return WhoWon::ComputerWon;

	if (RoundInfo.UserChoice == enGameOptions::Paper && RoundInfo.ComputerChoice == enGameOptions::Scissor)
		return WhoWon::ComputerWon;

	// إذا وصل هنا معناته لا تعادل ولا الكمبيوتر فاز فمعناته اللاعب اللي فاز
	return WhoWon::PlayerWon;

}

void SetWinnerScreenColor(WhoWon Winner)
{
	if (Winner == WhoWon::PlayerWon)
	{
		system("color 2F");
	}
	else if (Winner == WhoWon::ComputerWon)
	{
		system("color 4F");
		cout << "\a";
	}
	else
	{
		system("color 8F");
	}
}

void PrintRoundDetails(stRoundInfo RoundInfo)
{

	cout << "\n------------------------- Round [" << RoundInfo.RoundNumber << "] -------------------------" << endl;
	cout << "Player1 Choice : " << ConverChoiceToName(RoundInfo.UserChoice) << endl;
	cout << "Computer Choice : " << ConverChoiceToName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner : [" << ConvertWinnerToName(RoundInfo.RoundWinner) << "] " << endl;
	cout << "-------------------------------------------------------------" << endl;

	SetWinnerScreenColor(RoundInfo.RoundWinner);

}

void UpdateGameResults(stRoundInfo RoundInfo, stGameInfo & GameInfo)
{
	if (RoundInfo.RoundWinner == WhoWon::PlayerWon)
	{
		GameInfo.HowManyPlayerWon++;
	}
	else if (RoundInfo.RoundWinner == WhoWon::ComputerWon)
	{
		GameInfo.HowManyComputerWon++;
	}	
	else
	{
		GameInfo.HowManyDraw++;
	}
}

void LoopForRounds(stGameInfo &GameInfo)
{

	for (int i = 1; i <= GameInfo.HowManyRounds; i++)
	{
		stRoundInfo RoundInfo;

		RoundInfo.RoundNumber = i;
		cout << "\nRound [" << RoundInfo.RoundNumber << "] Begins : " << endl;


		RoundInfo.UserChoice = UserChoice();
		RoundInfo.ComputerChoice = ComputerChoice();
		RoundInfo.RoundWinner = WhoWonPlayerOrComputer(RoundInfo);


		UpdateGameResults(RoundInfo, GameInfo);
		PrintRoundDetails(RoundInfo);


	}
	
}

void PrintGameResult(stGameInfo GameInfo)
{
	cout << Tabs(6) << "---------------------------------------------------" << endl;
	cout << Tabs(6) << "                    Game Over                      " << endl;
	cout << Tabs(6) << "---------------------------------------------------" << endl;
	cout << Tabs(6) << "         +++++++++ Game Result ++++++++		      " << endl;
	cout << Tabs(6) << "---------------------------------------------------" << endl;
	cout << Tabs(6) << "Game Rounds        : " << GameInfo.HowManyRounds << endl;
	cout << Tabs(6) << "Player won times   : " << GameInfo.HowManyPlayerWon << endl;
	cout << Tabs(6) << "Computer won times : " << GameInfo.HowManyComputerWon << endl;
	cout << Tabs(6) << "Draw times         : " << GameInfo.HowManyDraw << endl;
	cout << Tabs(6) << "Final Winner       : " << ConvertWinnerToName(WhoIsTheWinner(GameInfo)) << endl;
	cout << Tabs(6) << "---------------------------------------------------" << endl;

	SetWinnerScreenColor(WhoIsTheWinner(GameInfo));
}

char DoYouWantToContinue()
{
	char WannaContinue;

	do
	{
		cout << "\n" << Tabs(6) << "Do u want to continue play ? [Y] Yes , [N] No : ";
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
		system("cls");

		stGameInfo GameInfo;
		GameInfo.HowManyRounds = ReadHowManyRounds();

		LoopForRounds(GameInfo);
		PrintGameResult(GameInfo);

	} while (ReGameOrClose(DoYouWantToContinue()) == ContinueOrCloseGame::ContinueGame);


}



int main()
{
	srand((unsigned)time(NULL));

	FinalGame();

	cout << Tabs(9) << "By waz.";
}