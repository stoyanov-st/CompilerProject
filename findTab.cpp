#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, Attribute> symbolTable;

int findTab(string sym, Attribute attr)
{
	if(!symbolTable.count(sym))
	{
		symbolTable.insert(sym, attr);
	}
	else return symbolTable.count(sym);
}
