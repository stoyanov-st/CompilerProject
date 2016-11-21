#include "Grammar.h"

using namespace std;

queue<int> bufferList;

/*
void zBlock(string nextSymbol)
{
	headBlock(nextSymbol);

	if (nextSymbol != "tremor")
	{
		errorBlock();
	}


}
*/

void errorBlock(string errorMessage)
{
	System::String^ errorString ( "" ); 
	errorString += gcnew System::String(errorMessage.c_str());
	System::Windows::Forms::MessageBox::Show(errorString);
	return;
}

void headBlock(string nextSymbol)
{
	if (nextSymbol != "var")
	{
		errorBlock("Head Error!");
	}
	else
	{
		bufferList.pop();
		if (symbolTable.at(bufferList.front()).second == 1)
		{
			bufferList.pop();
			if (symbolTable.at(bufferList.front()).first == ".")
			{
				bufferList.pop();
			}
			else
			{
				errorBlock("Dot not present! End Line properly! MOFO");
			}
		}
		else
		{
			errorBlock("ID Error!");
		}
	}
}

void logicBlock(string nextSymbol)
{
	statementBlock(nextSymbol);

	while (symbolTable.at(bufferList.front()).first == "!")
	{
		bufferList.pop();
		if (symbolTable.at(bufferList.front()).first == "tardo")
		{
			break;
		}
		else
		{
			statementBlock(symbolTable.at(bufferList.front()).first);
		}
	}
}

void statementBlock(string nextSymbol)
{
	
	if(!bufferList.empty() && symbolTable.at(bufferList.front()).first == "tobe")
	{
		bufferList.pop();
		expresionBlock(symbolTable.at(bufferList.front()).first);
		if (!bufferList.empty() && symbolTable.at(bufferList.front()).first != "et")
		{
			errorBlock("Missing et expression!");
		}
		else
		{
			bufferList.pop();
			statementBlock(symbolTable.at(bufferList.front()).first);
			if (!bufferList.empty() && symbolTable.at(bufferList.front()).first == "ornottobe")
			{
				bufferList.pop();
				statementBlock(symbolTable.at(bufferList.front()).first);
			}
		}
	}
	else if (!bufferList.empty() && symbolTable.at(bufferList.front()).first == "locus")
	{
		bufferList.pop();
		expresionBlock(symbolTable.at(bufferList.front()).first);
		statementBlock(symbolTable.at(bufferList.front()).first);
	}
	else if (!bufferList.empty() && symbolTable.at(bufferList.front()).second == 1)
	{
		bufferList.pop();
		if (!bufferList.empty() && symbolTable.at(bufferList.front()).first == "=")
		{
			bufferList.pop();
			expresionBlock(symbolTable.at(bufferList.front()).first);
		}
	}
	else
	{
		errorBlock("Error in logic expression!");
	}

}

void expresionBlock(string nextSymbol)
{
	termBlock(nextSymbol);
	if (!bufferList.empty() && symbolTable.at(bufferList.front()).first == "+")
	{
		bufferList.pop();
		termBlock(symbolTable.at(bufferList.front()).first);
	}
	else if (!bufferList.empty() && symbolTable.at(bufferList.front()).first == "-")
	{
		bufferList.pop();
		termBlock(symbolTable.at(bufferList.front()).first);
	}
}

void termBlock(string nextSymbol)
{
	factorBlock(nextSymbol);
	if (symbolTable.at(bufferList.front()).first == "*")
	{
		bufferList.pop();
		factorBlock(symbolTable.at(bufferList.front()).first);
	}
	else if (symbolTable.at(bufferList.front()).first == "/")
	{
		bufferList.pop();
		factorBlock(symbolTable.at(bufferList.front()).first);
	}
}

void factorBlock(string nextSymbol)
{
	if ( nextSymbol == "(")
	{
		bufferList.pop();
		expresionBlock(symbolTable.at(bufferList.front()).first);
		if (!bufferList.empty() && symbolTable.at(bufferList.front()).first != ")")
		{
			errorBlock("Factor Error!");
		}
		else
		{
			bufferList.pop();
		}
	}
	else if (!bufferList.empty() && (symbolTable.at(bufferList.front()).second == 1 || symbolTable.at(bufferList.front()).second == 2))
	{
		bufferList.pop();
	}
	else if (nextSymbol == "const")
	{
		bufferList.pop();
	}
	else
	{
		errorBlock("Factor Error!");
	}
}

void syntaxAnalize(queue<int> list)
{
	bufferList = list;
	if (!bufferList.empty())
	{

		headBlock(symbolTable[bufferList.front()].first);

		if (!bufferList.empty() && symbolTable.at(bufferList.front()).first == "tremor")
		{
			bufferList.pop();
		}
		else
		{
			errorBlock("Tremor error!");
		}

		if (!bufferList.empty() && symbolTable.at(bufferList.front()).first == "tardo")
		{
			bufferList.pop();
		}
		else if (!bufferList.empty() && symbolTable.at(bufferList.front()).first != "tardo")
		{
			logicBlock(symbolTable.at(bufferList.front()).first);

			if (symbolTable.at(bufferList.front()).first == "tardo")
			{
				bufferList.pop();
				System::Windows::Forms::MessageBox::Show("Success");
			}
			else
			{
				errorBlock("Tardo error!");
			}
		}
	}
}