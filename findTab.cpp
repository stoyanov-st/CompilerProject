#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <queue>

using namespace std;

#include "../ep/EP-2/EP-2/printQueue.h"
/*SymbolTable Attributes
	*********************
		* 1 - Letter
		* 2 - Number
		* 3 - Operator
	*********************
*/

map<string, int> symbolTable;
queue<int> positionList;

regex letterRegex("[A-Za-z]");
regex _EOLRegex("[;]"); // lacks special chars
regex numberRegex("[[:digit:]]");
regex operatorRegex("[\\+|-|*|<|>|=|!|\\?]");

int findTab(string sym, int attr){

	return symbolTable[sym] = attr;
	
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
				positionList.push(findTab(wordArray, 1));
				wordArray = "";
			}
		}

		//Check if it is number
		else if (regex_match(currentChar, numberRegex))
		{
			wordArray.append(currentChar);

			//Check for floating point
			if (currentChar.find('.') && regex_match(to_string(nextChar), numberRegex))
			{
				wordArray.append(currentChar);
			}

			if (isspace(nextChar) || regex_match(to_string(nextChar), _EOLRegex) || regex_match(to_string(nextChar), operatorRegex))
			{
				positionList.push(findTab(wordArray, 2));
				wordArray = "";
			}
		}

		//Check for operator
		else if (regex_match(currentChar, operatorRegex))
		{
			wordArray += currentChar;

			if (isspace(nextChar) || regex_match(to_string(nextChar), _EOLRegex))
			{
				positionList.push(findTab(wordArray, 3));
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
		printQueue(positionList);
		cout << endl;
	
	system("pause");
	return 0;
}
