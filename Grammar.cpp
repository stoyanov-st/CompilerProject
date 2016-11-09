#include "Grammar.h"

using namespace std;

void zBlock(string nextSymbol)
{
	headBlock(nextSymbol);

	if (nextSymbol != "tremor")
	{
		errorBlock();
	}


}

void errorBlock()
{
	System::Windows::Forms::MessageBox::Show("String");
}

void headBlock(string nextSymbol)
{
	if (nextSymbol != "var")
	{
		System::Windows::Forms::MessageBox::Show("HEadError");
	}
	
}

void logicBlock(string nextSymbol)
{
}

void statementBlock(string nextSymbol)
{
}

void expresionBlock(string nextSymbol)
{
}

void termBlock(string nextSymbol)
{
}

void factorBlock(string nextSymbol)
{
}

void syntaxAnalize(queue<int> list)
{
	while (!list.empty())
	{
		zBlock(symbolTable.at(list.front()).first);
		list.pop();
	}
}