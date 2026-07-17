// Project 01 - Rock Paper Scissors Game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


enum enGameOptions { Stone = 1, Paper, Scissor };
enum enWhoWon { PlayerWon = 1, ComputerWon, NobodyWon};

struct stRoundInfo
{
	int RoundNumber = 0;
	enGameOptions PlayerChoice;
	enGameOptions ComputerChoice;
	enWhoWon RoundWinner;
	string WinnerName = "";
};

struct stGameInfo
{
	int HowManyRounds = 0;
	int HowManyPlayerWon = 0;
	int HowManyComputerWon = 0;
	int HowManyDraw = 0;
	enWhoWon GameWinner;
	string GameWinnerName = "";
};



// Helper functions
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

int RandomNumber(int From, int To)
{
	int RandomNumber = rand() % (To - From + 1) + From;

	return RandomNumber;
}

string ConvertChoiceToName(enGameOptions UserChoice)
{
	string arrGameChoice[3] = { "Stone" , "Paper", "Scissor" };

	return arrGameChoice[UserChoice - 1];
}

string ConvertWinnerToName(enWhoWon WinnerName)
{
	string arrWinnerName[3] = { "Player" , "Computer" , "Nobody" };

	return arrWinnerName[WinnerName - 1];
}

string Tabs(int NumberOfTabs)
{
	string Tab = "";

	for (int i = 1; i <= NumberOfTabs; i++)
	{
		Tab = Tab + "\t";
	}

	return Tab;
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

enWhoWon WhoWonTheRound(stRoundInfo RoundInfo)
{
	
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
		return enWhoWon::NobodyWon;

	if (RoundInfo.PlayerChoice == enGameOptions::Stone && RoundInfo.ComputerChoice == enGameOptions::Paper)
		return enWhoWon::ComputerWon;

	if (RoundInfo.PlayerChoice == enGameOptions::Scissor && RoundInfo.ComputerChoice == enGameOptions::Stone)
		return enWhoWon::ComputerWon;

	if (RoundInfo.PlayerChoice == enGameOptions::Paper && RoundInfo.ComputerChoice == enGameOptions::Scissor)
		return enWhoWon::ComputerWon;

	// إذا وصل هنا معناته لا تعادل ولا الكمبيوتر فاز فمعناته اللاعب اللي فاز
	return enWhoWon::PlayerWon;

}

enWhoWon WhoWonTheGame(int HowManyPlayerWon, int HowManyComputerWon)
{
	if (HowManyPlayerWon > HowManyComputerWon)
		return enWhoWon::PlayerWon;
	else if (HowManyComputerWon > HowManyPlayerWon)
		return enWhoWon::ComputerWon;
	else
		return enWhoWon::NobodyWon;
}

void SetWinnerScreenColor(enWhoWon Winner)
{

	switch (Winner)
	{
	case enWhoWon::PlayerWon:
		system("color 2F");
		break;

	case enWhoWon::ComputerWon:
		system("color 4F");
		cout << "\a";
		break;

	default:
		system("color 8F");
		break;
	}
}

void PrintRoundDetails(stRoundInfo RoundInfo)
{

	cout << "\n------------------------- Round [" << RoundInfo.RoundNumber << "] -------------------------" << endl;
	cout << "Player1 Choice : " << ConvertChoiceToName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice : " << ConvertChoiceToName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner : [" << RoundInfo.WinnerName << "] " << endl;
	cout << "-------------------------------------------------------------" << endl;

	SetWinnerScreenColor(RoundInfo.RoundWinner);

}

stGameInfo FillGameResults(int HowManyRounds, int HowManyPlayerWon, int HowManyComputerWon, int HowManyDraw)
{
	stGameInfo Results;

	Results.HowManyRounds = HowManyRounds;
	Results.HowManyPlayerWon = HowManyPlayerWon;
	Results.HowManyComputerWon = HowManyComputerWon;
	Results.HowManyDraw = HowManyDraw;
	Results.GameWinner = WhoWonTheGame(HowManyPlayerWon, HowManyComputerWon);
	Results.GameWinnerName = ConvertWinnerToName(Results.GameWinner);

	return Results;
}

stGameInfo PlayGame(int HowManyRounds)
{

	int HowManyPlayerWon = 0, HowManyComputerWon = 0, HowManyDraw = 0;

	for (int i = 1; i <= HowManyRounds; i++)
	{
		stRoundInfo RoundInfo;

		RoundInfo.RoundNumber = i;
		cout << "\nRound [" << RoundInfo.RoundNumber << "] Begins : " << endl;


		RoundInfo.PlayerChoice = UserChoice();
		RoundInfo.ComputerChoice = ComputerChoice();
		RoundInfo.RoundWinner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = ConvertWinnerToName(RoundInfo.RoundWinner);


		if (RoundInfo.RoundWinner == enWhoWon::PlayerWon)
			HowManyPlayerWon++;

		else if (RoundInfo.RoundWinner == enWhoWon::ComputerWon)
			HowManyComputerWon++;

		else
			HowManyDraw++;


		PrintRoundDetails(RoundInfo);


	}
	
	return FillGameResults(HowManyRounds, HowManyPlayerWon, HowManyComputerWon, HowManyDraw);
}

void PrintFinalGameResult(stGameInfo GameInfo)
{
	cout << Tabs(6) << "---------------------------------------------------"  << endl;
	cout << Tabs(6) << "                    Game Over                      "  << endl;
	cout << Tabs(6) << "---------------------------------------------------"  << endl;
	cout << Tabs(6) << "         +++++++++ Game Result ++++++++		       "  << endl;
	cout << Tabs(6) << "---------------------------------------------------"  << endl;
	cout << Tabs(6) << "Game Rounds        : " << GameInfo.HowManyRounds      << endl;
	cout << Tabs(6) << "Player won times   : " << GameInfo.HowManyPlayerWon   << endl;
	cout << Tabs(6) << "Computer won times : " << GameInfo.HowManyComputerWon << endl;
	cout << Tabs(6) << "Draw times         : " << GameInfo.HowManyDraw        << endl;
	cout << Tabs(6) << "Final Winner       : " << GameInfo.GameWinnerName     << endl;
	cout << Tabs(6) << "---------------------------------------------------"  << endl;

	SetWinnerScreenColor(GameInfo.GameWinner);
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

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void FinalGame()
{

	char ContinueChoice;

	do
	{

		ResetScreen();

		stGameInfo GameInfo = PlayGame(ReadHowManyRounds());
		PrintFinalGameResult(GameInfo);

		ContinueChoice = DoYouWantToContinue();

	} while (ContinueChoice == 'Y' || ContinueChoice == 'y');


}



int main()
{
	srand((unsigned)time(NULL));

	FinalGame();

	cout << Tabs(9) << "By waz.";
}