// Project 02 - Math Game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


enum enQuestionLevel { Easy = 1, Med, Hard, MixLevel};
enum enOperationType { Add = 1, Subtract, Multiplication, Division, MixType };


struct stQuestionInfo
{
	int NumberOne = 0;
	int NumberTwo = 0;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	enQuestionLevel Level;
	enOperationType OperationTy;
	bool AnswerResult = false;
};

struct stQuizInfo
{
	stQuestionInfo QuestionList[100];
	int NumberOfQuestions = 0;
	int NumberOfRightAnswer = 0;
	int NumberOfWrongAnswer = 0;
	enQuestionLevel QuestionsLevel;
	enOperationType OperationType;
	bool IsPass = false;
};



// HelperFunctions
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

string ConvertOpTypeToSymbol(enOperationType type)
{
	switch (type)
	{
	case enOperationType::Add:
		return "+";
	case enOperationType::Subtract:
		return "-";
	case enOperationType::Multiplication:
		return "*";
	case enOperationType::Division:
		return "/";
		
	default:
		return "Mix";
	}
}

string ConvertLevelToName(enQuestionLevel level)
{
	string arrLevel[4] = { "Easy" , "Med" , "Hard" , "Mix" };

	return arrLevel[level - 1];
}

string ConvertBoolToName(bool IsPass)
{
	if (IsPass)
		return "Pass :)";
	else
		return "Fail :(";
}


// ReadFunctions
int ReadHowManyQuestions()
{
	int NumberOfQuestions = ReadNumberInRange("How Many Questions do u want to answer ? : ", 1, 100);

	return NumberOfQuestions;
}

int ReadQuestionAnswer()
{
	int PlayerAnswer;
	cin >> PlayerAnswer;

	return PlayerAnswer;
}

enQuestionLevel ReadQuestionsLevel()
{
	int UserNumber;

	cout << "Enter Questions Level : [1] Easy, [2] Medium, [3] Hard, [4] Mix : ";
	UserNumber = ReadNumberInRange("", 1, 4);

	return enQuestionLevel(UserNumber);
}

enOperationType ReadOperationType()
{
	int UserNumber;

	cout << "Enter Operation Type : [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix : ";
	UserNumber = ReadNumberInRange("", 1, 5);

	return enOperationType(UserNumber);
}




// PrintFunctions
void PrintQuestions(stQuizInfo& Quizz, int QuestionNumber)
{
	cout << "\nQuestion [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]" << endl;
	cout << Quizz.QuestionList[QuestionNumber].NumberOne << endl;
	cout << Quizz.QuestionList[QuestionNumber].NumberTwo << "  " << ConvertOpTypeToSymbol(Quizz.QuestionList[QuestionNumber].OperationTy) << endl;
	cout << "____________________" << endl;
}

void PrintQuizzResult(stQuizInfo Quiz)
{
	cout << Tabs(8) << "----------------------------" << endl;
	cout << Tabs(8) << " Final Results is " << ConvertBoolToName(Quiz.IsPass) << endl;
	cout << Tabs(8) << "----------------------------" << endl;
	cout << Tabs(8) << "Number of Questions     : " << Quiz.NumberOfQuestions << endl;
	cout << Tabs(8) << "Questions Level         : " << ConvertLevelToName(Quiz.QuestionsLevel) << endl;
	cout << Tabs(8) << "Operations Type         : " << ConvertOpTypeToSymbol(Quiz.OperationType) << endl;
	cout << Tabs(8) << "Number of Right Answers : " << Quiz.NumberOfRightAnswer << endl;
	cout << Tabs(8) << "Number of Wrong Answers : " << Quiz.NumberOfWrongAnswer << endl;
}

void PrintScreenColor(bool boo)
{
	if (boo)
		system("color 2F");
	else
	{
		system("color 4F");
		cout << "\a";
	}
}


// GameFunctions
int SimpleCalculator(stQuestionInfo numbers)
{

	switch (numbers.OperationTy)
	{
	case enOperationType::Add:
		return numbers.NumberOne + numbers.NumberTwo;
	case enOperationType::Subtract:
		return numbers.NumberOne - numbers.NumberTwo;
	case enOperationType::Multiplication:
		return numbers.NumberOne * numbers.NumberTwo;
	case enOperationType::Division:
		return numbers.NumberOne / numbers.NumberTwo;

	default:
		return numbers.NumberOne + numbers.NumberTwo;
	}
}

enOperationType GetRandomOperationType()
{
	int RandomInt = RandomNumber(1, 4);

	return enOperationType(RandomInt);
}

stQuestionInfo GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType OperationType)
{
	stQuestionInfo Question;

	if (QuestionLevel == enQuestionLevel::MixLevel)
		QuestionLevel = enQuestionLevel(RandomNumber(1, 3));

	if (OperationType == enOperationType::MixType)
		OperationType = GetRandomOperationType();

	Question.OperationTy = OperationType;

	switch (QuestionLevel)
	{
	case enQuestionLevel::Easy:
		Question.NumberOne = RandomNumber(1, 100);
		Question.NumberTwo = RandomNumber(1, 100);
		Question.CorrectAnswer = SimpleCalculator(Question);
		Question.Level = QuestionLevel;
		return Question;

	case enQuestionLevel::Med:
		Question.NumberOne = RandomNumber(100, 500);
		Question.NumberTwo = RandomNumber(100, 500);
		Question.CorrectAnswer = SimpleCalculator(Question);
		Question.Level = QuestionLevel;
		return Question;

	case enQuestionLevel::Hard:
		Question.NumberOne = RandomNumber(500, 1000);
		Question.NumberTwo = RandomNumber(500, 1000);
		Question.CorrectAnswer = SimpleCalculator(Question);
		Question.Level = QuestionLevel;
		return Question;
	default: // Mix Questions
		Question.NumberOne = RandomNumber(1, 1000);
		Question.NumberTwo = RandomNumber(1, 1000);
		Question.CorrectAnswer = SimpleCalculator(Question);
		Question.Level = QuestionLevel;
		return Question;
	}

}

void GenerateQuizzQuestions(stQuizInfo &quiz)
{
	for (int i = 0; i < quiz.NumberOfQuestions; i++)
	{
		quiz.QuestionList[i] = GenerateQuestion(quiz.QuestionsLevel, quiz.OperationType);
	}
}

void CorrectTheQuestion(stQuizInfo& Quizz, int QuestionNumber)
{
	if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = false;
		Quizz.NumberOfWrongAnswer++;

		cout << "\nWrong Answer :(" << endl;
		cout << "The Right Answer is : " << Quizz.QuestionList[QuestionNumber].CorrectAnswer << endl;
	}
	else
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = true;
		Quizz.NumberOfRightAnswer++;

		cout << "\nRight Answer :)" << endl;
	}

	PrintScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
		
}

void AskAndCorrectQuestionListAnswers(stQuizInfo& Quizz)
{
	for (int QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
	{
		PrintQuestions(Quizz, QuestionNumber);
		Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();

		CorrectTheQuestion(Quizz, QuestionNumber);
	}

	Quizz.IsPass = (Quizz.NumberOfRightAnswer >= Quizz.NumberOfWrongAnswer);
}

void PlayMathGame()
{
	stQuizInfo Quiz;

	Quiz.NumberOfQuestions = ReadHowManyQuestions();
	Quiz.QuestionsLevel = ReadQuestionsLevel();
	Quiz.OperationType = ReadOperationType();

	GenerateQuizzQuestions(Quiz);
	AskAndCorrectQuestionListAnswers(Quiz);
	PrintQuizzResult(Quiz);
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
		PlayMathGame();

		WannaContinue = DoYouWantToContinue();

	} while (WannaContinue == 'Y' || WannaContinue == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	FinalGame();

	cout << Tabs(9) << "By waz.";
}