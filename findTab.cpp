#include <iostream>
#include <map>
#include <deque>
#include <string>
#include <regex>

using namespace std;

/*SymbolTable Attributes
	*********************
		* 1 - Letter
		* 2 - Number
		* 3 - Operator
	*********************
*/

map<string, int> symbolTable;
deque<int> positionList;

regex letterRegex("[A-Za-z]");
regex _EOLRegex("[;]"); // lacks special chars
regex numberRegex("[[:digit:]]");
regex operatorRegex("[\\+|-|*|<|>|=|!|\\?]");

int findTab(string sym, int attr){
	
	if(symbolTable.count(sym) == 0)
	{
		symbolTable.emplace(sym, attr);
		map<string, int>::iterator it = symbolTable.find(sym);

		return distance(symbolTable.begin(), it);
	}

	else
	{
		map<string, int>::iterator it = symbolTable.find(sym);

		return distance(symbolTable.begin(), it);
	}
		
}

void lexicalAnalyze(string inputString)
{
	string wordArray, currentChar;
	char nextChar;

	for (unsigned int i = 0, length = inputString.length() ; i+1 <= length; i++)
	{
	
		currentChar.push_back(inputString.at(i));
		((i + 1) < length) ? nextChar = inputString.at(i + 1) : nextChar = ' ';

		//Check if it is a letter
		if (regex_match(currentChar, letterRegex))
		{
			wordArray.append(currentChar);
			
			if (isspace(nextChar) || regex_match(to_string(nextChar),_EOLRegex) || regex_match(to_string(nextChar), operatorRegex))
			{
				positionList.push_back(findTab(wordArray, 1));
				wordArray = "";
			}
		}

		//Check if it is number
		else if (regex_match(currentChar, numberRegex))
		{
			wordArray.append(currentChar);

			//Check for floating point
			if (currentChar.find('.'))
			{
				wordArray.append(currentChar);
			}

			if (isspace(nextChar) || regex_match(to_string(nextChar), _EOLRegex) || regex_match(to_string(nextChar), operatorRegex))
			{
				positionList.push_back(findTab(wordArray, 2));
				wordArray = "";
			}
		}

		//Check for operator
		else if (regex_match(currentChar, operatorRegex))
		{
			wordArray += currentChar;

			if (isspace(nextChar) || regex_match(to_string(nextChar), _EOLRegex))
			{
				positionList.push_back(findTab(wordArray, 3));
				wordArray = wordArray = "";;
			}
		}

		currentChar = "";
	}
}

int main(void){
	
	string inputCodeSnippet;

		cout << "Enter input snippet of code to be compiled, please: " << endl;
		getline(cin, inputCodeSnippet);
		lexicalAnalyze(inputCodeSnippet);
		for (auto i = positionList.begin(); i != positionList.end(); i++)
		{
			cout << *i << endl;
		}
		cout << endl;
	
	system("pause");
	return 0;
}