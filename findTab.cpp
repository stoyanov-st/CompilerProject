#include <iostream>
#include <map>
#include <list>
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
list<int> positionList;

regex letterRegex("[^A-Za-z\\w]");
regex whitespaceOrEOLRegex("[[;]?\\s]"); // lacks special chars
regex numberRegex("[0-9]\\d");
regex operatorRegex("[\+\-\*\/\<\>\=\!\?\]");

int findTab(string sym, int attr){
	
	if(symbolTable.count(sym) == 0)
	{
		symbolTable[sym] =  attr;
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
	char* wordArray = new char[];

	for (int i = 0; i < inputString.size; i++)
	{

		//Check if it is a letter
		if (regex_match(to_string(inputString.at(i)), letterRegex))
		{
			wordArray += inputString.at(i);

			if (regex_match(to_string(inputString.at(i + 1)), whitespaceOrEOLRegex) || regex_match(to_string(inputString.at(i+1)), operatorRegex))
			{
				positionList.insert(positionList.end, findTab(wordArray, 1));
				wordArray = new char[];
			}
		}

		//Check if it is number
		if (regex_match(to_string(inputString.at(i)), numberRegex))
		{
			wordArray += inputString.at(i);

			//Check for floating point
			if (inputString.at(i) ==  '.')
			{
				wordArray += inputString.at(i);
			}

			if (regex_match(to_string(inputString.at(i + 1)), whitespaceOrEOLRegex) || regex_match(to_string(inputString.at(i+1)), operatorRegex))
			{
				positionList.insert(positionList.end, findTab(wordArray, 2));
				wordArray = new char[];
			}
		}

		//Check for operator
		if (regex_match(to_string(inputString.at(i)), operatorRegex))
		{
			wordArray += inputString.at(i);

			if (regex_match(to_string(inputString.at(i + 1)), whitespaceOrEOLRegex))
			{
				positionList.insert(positionList.end, findTab(wordArray, 3));
				wordArray = new char[];
			}
		}
	}

	/*for each (char lex in inputString)
	{
		if (regex_match(to_string(lex), letterRegex) ) 
		{

		}
		else
		{
			cout << regex_match(to_string(lex), letterRegex);
		}
	}*/
}

int main(void){
	
	char* inputCodeSnippet = new char[50];

		cout << "Enter input snippet of code to be compiled, please: " << endl;
		cin >> inputCodeSnippet;
		lexicalAnalyze(inputCodeSnippet);
		//cout << "Sym, attr pair: " << findTab(inputCodeSnippet);
		cout << endl;
	
	system("pause");
	return 0;
}
