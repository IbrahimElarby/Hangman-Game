

#include <iostream>
#include <fstream>
#include <string>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
	// Portotyping Function
	void StartGame(); 
	string DeclaringWordList();
	string DeclaringMystreyWord(string);
	void GameDisplay(int, string);
	char GuessingLetter();
	void GameOver(string);
	void WinningGame(string);

	srand(time(NULL));//Creating Random Seed
	int Tries = 6; //Declaring Number of Tries
	
	StartGame();
	string Word = DeclaringWordList();
	string MystreyWord= DeclaringMystreyWord(Word);
	while (Tries > 0)
	{

		bool RightGuess = false;
		char Guess = GuessingLetter();
		for (int i = 0; i <= MystreyWord.length(); i++)
		{
			 
			if (Word[i] == Guess)
			{
				MystreyWord[i] = Guess;
				RightGuess = true;
			}
			
			
		}
		if(RightGuess==false)
		{
			Tries--;
		}
		if (MystreyWord == Word)
		{
			WinningGame(Word);
			break;
		}
		else
		{
			GameDisplay(Tries, MystreyWord);
		}
		
		
		
		
	}
	GameOver(Word);

	return 0;

}
void StartGame()
{
	char AnyChar;
	cout << "Welcome to the Game\n";
	cout << "Press any botton to continue\n";
	cin >> AnyChar;
}
string DeclaringWordList()
{

	vector<string> WordList;
	string line;
	ifstream myfile("1-1000.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			WordList.push_back(line);
		}
		myfile.close();
	}

	else cout << "Unable to open file";
	int RandomNum = rand() % WordList.size();
	string Word = WordList[RandomNum];
	return Word;
}
string DeclaringMystreyWord(string Word)
{
	string MystreyWord(Word.length(), '#');
	return MystreyWord;
}
void GameDisplay(int Tries, string MystreyWord)
{
	cout << "Your word is \n\n" << MystreyWord << endl;
	cout << "You have " << Tries << " guesses left" << endl;
}
char GuessingLetter()
{
	char Guess;
	cout << "Guess a Letter" << endl;
	cin >> Guess;
	return Guess;
}
void GameOver(string Word)
{
	cout << "________________" << endl;
	cout << "       }        " << endl;
	cout << "       O        " << endl;
	cout << "       |        " << endl;
	cout << "     / | \\     " << endl;
	cout << "    /  |  \\     " << endl;
	cout << "       |        " << endl;
	cout << "      / \\      " << endl;
	cout << "     /   \\      " << endl;
	cout << "                " << endl;
	cout << "________________" << endl;
	cout << "  Game Over \n\n your word is " << Word << endl;
}
void WinningGame(string Word)
{
	cout << "Congratulations you won " << endl;
	cout << "The word is  " << Word << endl;
}