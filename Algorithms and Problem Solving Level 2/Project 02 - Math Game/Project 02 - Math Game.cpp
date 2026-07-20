// Project 02 - Math Game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


enum enQuestionLevel { Easy = 1, Med, Hard, MixLevel};
enum enOperationType { Add = 1, Subtract, Multiplication, Division, MixType };
enum enPassOrFail { Pass = 1, Fail, Draw};


struct stNumbersInfo
{
	int NumberOne = 0;
	int NumberTwo = 0;
};

struct stGameInfo
{
	int NumberOfQuestions = 0;
	int NumberOfRightAnswer = 0;
	int NumberOfWrongAnswer = 0;
	enQuestionLevel QuestionsLevel;
	enOperationType OperationType;
	enPassOrFail PassOrFail;
	string PassOrFailName = "";
};


string Tabs(int NumbersOfTabs)
{
	string Tabs = "";

	for (int i = 1; i <= NumbersOfTabs; i++)
	{
		Tabs = Tabs + "\t";
	}

	return Tabs;
}

int ReadNumberInRange(string Message, int From, int To)
{
	int UserNumber;

	do
	{
		cout << Message;
		cin >> UserNumber;

		if (UserNumber < From || UserNumber > To)
			cout << "You have to choose number from " << From << " To " << To << endl;

	} while (UserNumber < From || UserNumber > To);

	return UserNumber;
}

int RandomNumber(int From, int To)
{
	int Randomnumber = rand() % (To - From + 1) + From;

	return Randomnumber;
}

int HowManyQuestions()
{
	int NumberOfQuestions = ReadNumberInRange("How Many Questions do u want to answer ? : ", 1, 100);

	return NumberOfQuestions;
}

string ConvertTypeToName(enOperationType type)
{
	string arrType[5] = {"+" , "-" , "*" , "/" , "Mix"};

	return arrType[type - 1];
}

string ConvertLevelToName(enQuestionLevel level)
{
	string arrLevel[4] = { "Easy" , "Med" , "Hard" , "Mix" };

	return arrLevel[level - 1];
}

void GetQuestions(stNumbersInfo &numbers, enQuestionLevel Level)
{

	switch (Level)
	{
	case enQuestionLevel::Easy:
		numbers.NumberOne = RandomNumber(1, 100);
		numbers.NumberTwo = RandomNumber(1, 100);
		break;
	case enQuestionLevel::Med:
		numbers.NumberOne = RandomNumber(200, 500);
		numbers.NumberTwo = RandomNumber(200, 500);
		break;
	case enQuestionLevel::Hard:
		numbers.NumberOne = RandomNumber(1000, 1500);
		numbers.NumberTwo = RandomNumber(1000, 1500);
		break;
	default: // Mix Questions
		numbers.NumberOne = RandomNumber(1, 1500);
		numbers.NumberTwo = RandomNumber(1, 1500);
		break;
	}

}

void PrintQuestions(stNumbersInfo numbers, enOperationType type)
{
	cout << numbers.NumberOne << endl;
	cout << numbers.NumberTwo << "  " << ConvertTypeToName(type) << endl;
	cout << "____________________" << endl;
}

enQuestionLevel ChooseQuestionsLevel()
{
	int UserNumber;

	cout << "Enter Questions Level : [1] Easy, [2] Medium, [3] Hard, [4] Mix : ";
	UserNumber = ReadNumberInRange("", 1, 4);

	return enQuestionLevel(UserNumber);
}

enOperationType ChooseOperationType()
{
	int UserNumber;

	cout << "Enter Operation Type : [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix : ";
	UserNumber = ReadNumberInRange("", 1, 5);

	return enOperationType(UserNumber);
}

void PrintRightOrWrong(int UserAnswer, int RightAnswer)
{
	if (UserAnswer == RightAnswer)
	{
		cout << "\nRight answer :)" << endl;
		system("color 2F");
	}
	else
	{
		cout << "\nWrong Asnwer :(" << endl;
		cout << "The Right Answer is : " << RightAnswer << endl;
		system("color 4F");
	}

}

string ConvertPassOrFailToName(enPassOrFail what)
{
	string arrNames[3] = { "YouWon!" , "YouLost!" , "Draw!" };

	return arrNames[what - 1];
}

enPassOrFail GetGameResult(stGameInfo GameInfo)
{
	if (GameInfo.NumberOfRightAnswer > GameInfo.NumberOfWrongAnswer)
		return enPassOrFail::Pass;
	else if (GameInfo.NumberOfWrongAnswer > GameInfo.NumberOfRightAnswer)
		return enPassOrFail::Fail;
	else
		return enPassOrFail::Draw;
}

stGameInfo FillGameResult(int HowManyQuestions, int HowManyRightAnswers, int HowManyWrongAnswers, enQuestionLevel QuestionLevel, enOperationType OperationType)
{
	stGameInfo results;

	results.NumberOfQuestions = HowManyQuestions;
	results.NumberOfRightAnswer = HowManyRightAnswers;
	results.NumberOfWrongAnswer = HowManyWrongAnswers;
	results.QuestionsLevel = QuestionLevel;
	results.OperationType = OperationType;
	results.PassOrFail = GetGameResult(results);
	results.PassOrFailName = ConvertPassOrFailToName(results.PassOrFail); 

	return results;
}

int GetTheResult(stNumbersInfo numbers, enOperationType type)
{

	switch (type)
	{
	case enOperationType::Add:
		return numbers.NumberOne + numbers.NumberTwo;
	case enOperationType::Subtract:
		return numbers.NumberOne - numbers.NumberTwo;
	case enOperationType::Multiplication:
		return numbers.NumberOne * numbers.NumberTwo;
	case enOperationType::Division:
		return numbers.NumberOne / numbers.NumberTwo;
	}
}

enOperationType GetRandomOperation()
{
	int RandomInt = RandomNumber(1, 4);

	return enOperationType(RandomInt);
}

stGameInfo PlayGame(int HowManyQuestions)
{
	stNumbersInfo Numbers;
	int UserAnswer = 0;
	int HowManyRightAnswers = 0;
	int HowManyWrongAsnwers = 0;

	enQuestionLevel QuestionLevel = ChooseQuestionsLevel();
	enOperationType OperationType = ChooseOperationType();
	enOperationType DynamicOperationType;

	for (int i = 1; i <= HowManyQuestions; i++)
	{

		cout << "\nQuestion [" << i << "/" << HowManyQuestions << "]" << endl;


		GetQuestions(Numbers, QuestionLevel);

		if (OperationType == enOperationType::MixType)
			DynamicOperationType = GetRandomOperation();
		else
			DynamicOperationType = OperationType;


		PrintQuestions(Numbers, DynamicOperationType);
		cin >> UserAnswer;

		int RightAnswer = GetTheResult(Numbers, DynamicOperationType);

		PrintRightOrWrong(UserAnswer, RightAnswer);

		if (UserAnswer == RightAnswer)
			HowManyRightAnswers++;
		else
			HowManyWrongAsnwers++;

	}

	return FillGameResult(HowManyQuestions, HowManyRightAnswers, HowManyWrongAsnwers, QuestionLevel, OperationType);
}

void PrintScreenColor(stGameInfo info)
{
	if (info.NumberOfRightAnswer > info.NumberOfWrongAnswer)
	{
		system("color 2F");
	}
	else if (info.NumberOfWrongAnswer > info.NumberOfRightAnswer)
	{
		system("color 4F");
	}
	else
	{
		system("color 8F");
	}

}

void PrintFinalResult(stGameInfo GameInfo)
{
	cout << Tabs(8) << "----------------------------" << endl;
	cout << Tabs(8) << " Final Results is " << GameInfo.PassOrFailName << endl;
	cout << Tabs(8) << "----------------------------" << endl;
	cout << Tabs(8) << "Number of Questions     : " << GameInfo.NumberOfQuestions << endl;
	cout << Tabs(8) << "Questions Level         : " << ConvertLevelToName(GameInfo.QuestionsLevel) << endl;
	cout << Tabs(8) << "Operations Type         : " << ConvertTypeToName(GameInfo.OperationType) << endl;
	cout << Tabs(8) << "Number of Right Answers : " << GameInfo.NumberOfRightAnswer << endl;
	cout << Tabs(8) << "Number of Wrong Answers : " << GameInfo.NumberOfWrongAnswer << endl;

	PrintScreenColor(GameInfo);
}

char DoYouWantToContinue()
{
	char WannaContinue;

	do
	{
		cout << "\n";
		cout << Tabs(7) << "Do u want to continue play ? [Y] Yes , [N] No : ";
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
	char WannaContinue;

	do
	{
		ResetScreen();

		stGameInfo Play = PlayGame(HowManyQuestions());
		PrintFinalResult(Play);

		WannaContinue = DoYouWantToContinue();

	} while (WannaContinue == 'Y' || WannaContinue == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	FinalGame();

	cout << Tabs(9) << "By waz.";
}