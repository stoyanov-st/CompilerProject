using namespace std;

#include "findTab.h"

/*SymbolTable Attributes
	*********************
		 1 - Letter
		 2 - Number
		 3 - Operator
	*********************
*/
vector<pair<string, int>> symbolTable;
queue<int> positionList;

regex letterRegex("[A-Za-z]");
//regex _EOLRegex("[;]"); not working // lacks special chars
regex numberRegex("[[:digit:]]");
char operators[] { '+', '-', '.', '!', '*', '/', '(', ')'};
string operatorString[]{ "+", "-", ".", "!", "*", "/", "(", ")", "=" };
int findTab(string sym, int attr) {

	if (find(symbolTable.begin(), symbolTable.end(), make_pair(sym, attr)) != symbolTable.end())
	{
		return distance(symbolTable.begin(), find(symbolTable.begin(), symbolTable.end(), make_pair(sym, attr)));
	}
	else
	{
		symbolTable.push_back(make_pair(sym, attr));
		return distance(symbolTable.begin(), find(symbolTable.begin(), symbolTable.end(), make_pair(sym, attr)));
	}	
}

void fillTable()
{
	symbolTable.push_back(make_pair("tremor", 1));
	symbolTable.push_back(make_pair("tardo", 1));
	symbolTable.push_back(make_pair("var", 1));
	symbolTable.push_back(make_pair("tobe", 1));
	symbolTable.push_back(make_pair("et", 1));
	symbolTable.push_back(make_pair("ornottobe", 1));
	symbolTable.push_back(make_pair("locus", 1));
}

void lexicalAnalyze(string inputString)
{
	string wordArray, currentChar;
	char nextChar;

	for (unsigned int i = 0, length = inputString.length(); i + 1 <= length; i++)
	{

		currentChar.push_back(inputString.at(i));
		((i + 1) < length) ? nextChar = inputString.at(i + 1) : nextChar = ' ';

		//Check if it is a letter
		if (regex_match(currentChar, letterRegex))
		{
			wordArray.append(currentChar);

			if (isspace(nextChar) || find(begin(operators), end(operators), nextChar) != end(operators))
			{
				positionList.push(findTab(wordArray, 1));
				wordArray = "";
			}
		}

		//Check if it is number
		else if (regex_match(currentChar, numberRegex))
		{
			wordArray.append(currentChar);

			//Check for floating point
			if (nextChar == '.' && count(wordArray.begin(), wordArray.end(), '.') == 0)
			{
				wordArray += nextChar;
			}
			else if (nextChar == '.' && count(wordArray.begin(), wordArray.end(), '.') > 0)
			{
				System::Windows::Forms::MessageBox::Show("Error! Not Allowed Multiple Floating Point Use!");
				break;
			}

			if (isspace(nextChar) || find(begin(operators), end(operators), nextChar) != end(operators))
			{
				positionList.push(findTab(wordArray, 2));
				wordArray = "";
			}
		}

		//Check for operator
		else if (find(begin(operatorString), end(operatorString), currentChar) != end(operatorString))
		{
			wordArray += currentChar;

			positionList.push(findTab(wordArray, 3));
			wordArray = wordArray = "";;

		}

		currentChar = "";
	}
}


/*
int main(void){

	string inputCodeSnippet;

		//cout << "Enter input snippet of code to be compiled, please: " << endl;
		//getline(cin, inputCodeSnippet);
		lexicalAnalyze(inputCodeSnippet);
		printQueue(positionList);
		cout << endl;

	system("pause");
	return 0;
}

*/
