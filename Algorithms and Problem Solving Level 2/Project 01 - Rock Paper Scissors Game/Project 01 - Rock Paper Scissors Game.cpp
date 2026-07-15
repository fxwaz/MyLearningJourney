// Project 01 - Rock Paper Scissors Game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enGameOptions { Stone = 1, Paper, Scissor };
enum WhoWon { PlayerWon = 1, ComputerWon, NobodyWon};
enum ContinueOrCloseGame { ContinueGame = 1, CloseGame};

struct stRoundDetails
{
	WhoWon RoundWinner;
	enGameOptions UserChoice;
	enGameOptions ComputerChoice;
};

struct stGameResults
{
	int Howmanyrounds = 0;
	int HowManyPlayerWon = 0;
	int HowManyComputerWon = 0;
	int HowManyDraw = 0;
};

// Helper functions
string WhoIsTheWinner(stGameResults PlayerVsComp)
{
	if (PlayerVsComp.HowManyPlayerWon > PlayerVsComp.HowManyComputerWon)
		return "Player";
	else if (PlayerVsComp.HowManyComputerWon > PlayerVsComp.HowManyPlayerWon)
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

WhoWon WhoWonPlayerOrComputer(enGameOptions userChoice, enGameOptions computerChoice)
{
	
	if (userChoice == computerChoice)
		return WhoWon::NobodyWon;

	// الآن يشيك إذا الكمبيوتر فاز ولالا
	if (userChoice == enGameOptions::Stone && computerChoice == enGameOptions::Paper)
		return WhoWon::ComputerWon;

	if (userChoice == enGameOptions::Scissor && computerChoice == enGameOptions::Stone)
		return WhoWon::ComputerWon;

	if (userChoice == enGameOptions::Paper && computerChoice == enGameOptions::Scissor)
		return WhoWon::ComputerWon;

	// إذا وصل هنا معناته لا تعادل ولا الكمبيوتر فاز فمعناته اللاعب اللي فاز
	return WhoWon::PlayerWon;

}

void RoundDetails(int RoundCount, stRoundDetails RoundDetails, stGameResults &GameDetails)
{

	if (RoundDetails.RoundWinner == WhoWon::PlayerWon)
	{
		system("color 2F");
		cout << "\n------------------------- Round [" << RoundCount << "] -------------------------" << endl;
		cout << "Player1 Choice : " << ConvertNumbersToNames(RoundDetails.UserChoice) << endl;
		cout << "Computer Choice : " << ConvertNumbersToNames(RoundDetails.ComputerChoice) << endl;
		cout << "Round Winner : [Player] " << endl;
		cout << "-------------------------------------------------------------" << endl;
		GameDetails.HowManyPlayerWon++;
	}
	else if (RoundDetails.RoundWinner == WhoWon::ComputerWon)
	{
		system("color 4F");
		cout << "\n------------------------- Round [" << RoundCount << "] -------------------------" << endl;
		cout << "Player1 Choice : " << ConvertNumbersToNames(RoundDetails.UserChoice) << endl;
		cout << "Computer Choice : " << ConvertNumbersToNames(RoundDetails.ComputerChoice) << endl;
		cout << "Round Winner : [Computer] " << endl;
		cout << "-------------------------------------------------------------" << endl;
		GameDetails.HowManyComputerWon++;
	}
	else
	{
		system("color 8F");
		cout << "\n------------------------- Round [" << RoundCount << "] -------------------------" << endl;
		cout << "Player1 Choice : " << ConvertNumbersToNames(RoundDetails.UserChoice) << endl;
		cout << "Computer Choice : " << ConvertNumbersToNames(RoundDetails.ComputerChoice) << endl;
		cout << "Round Winner : [NoBody] " << endl;
		cout << "-------------------------------------------------------------" << endl;
		GameDetails.HowManyDraw++;
	}


}

void LoopForRounds(stGameResults gameResults)
{

	for (int i = 1; i <= gameResults.Howmanyrounds; i++)
	{
		cout << "\nRound [" << i << "] Begins : " << endl;

		stRoundDetails roundDetails;

		roundDetails.UserChoice = UserChoice();
		roundDetails.ComputerChoice = ComputerChoice();
		roundDetails.RoundWinner = WhoWonPlayerOrComputer(roundDetails.UserChoice, roundDetails.ComputerChoice);

		RoundDetails(i, roundDetails, gameResults);
	}
}

void FinalResult(stGameResults gameResults)
{
	cout << "\t\t\t\t\t---------------------------------------------------" << endl;
	cout << "\t\t\t\t\t                    Game Over                      " << endl;
	cout << "\t\t\t\t\t---------------------------------------------------" << endl;
	cout << "\t\t\t\t\t         +++++++++ Game Result ++++++++		      " << endl;
	cout << "\t\t\t\t\t---------------------------------------------------" << endl;
	cout << "\t\t\t\t\tGame Rounds : " << gameResults.Howmanyrounds << "                 " << endl;
	cout << "\t\t\t\t\tPlayer won times : " << gameResults.HowManyPlayerWon << "      " << endl;
	cout << "\t\t\t\t\tComputer won times : " << gameResults.HowManyComputerWon << "  " << endl;
	cout << "\t\t\t\t\tDraw times : " << gameResults.HowManyDraw << "                 " << endl;
	cout << "\t\t\t\t\tFinal Winner : " << WhoIsTheWinner(gameResults) << endl;
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
		stRoundDetails roundDetails{};
		stGameResults gameResults;
		gameResults.Howmanyrounds = HowManyRounds();
		gameResults.HowManyPlayerWon = 0;
		gameResults.HowManyComputerWon = 0;
		gameResults.HowManyDraw = 0;

		LoopForRounds(gameResults);
		FinalResult(gameResults);

	} while (ReGameOrClose(DoYouWantToContinue()) == ContinueOrCloseGame::ContinueGame);


}



int main()
{
	srand((unsigned)time(NULL));

	FinalGame();

	cout << "\t\t\t\t\t\t\t\tBy waz.";
}