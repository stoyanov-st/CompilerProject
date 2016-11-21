using namespace std;
#include "printQueue.h"
using namespace System;

String^ printQueue(queue<int> queueToBePrinted)
{
	String^ bufferStringArray("");
	while (!queueToBePrinted.empty())
	{
		bufferStringArray += queueToBePrinted.front();
		bufferStringArray += Environment::NewLine;

		queueToBePrinted.pop();
	}
	return bufferStringArray;
}

String^ printMap(vector<pair<string, int>> mapToBePrinted)
{
	String^ bufferStringArray("");

	for (vector<pair<string, int>>::iterator i = mapToBePrinted.begin(); i != mapToBePrinted.end(); i++)
	{
		bufferStringArray += distance(mapToBePrinted.begin(), i);
		bufferStringArray += "  ";
		bufferStringArray += gcnew String(i->first.c_str());
		bufferStringArray += "    ";
		bufferStringArray += i->second;
		bufferStringArray += Environment::NewLine;
	}

	return bufferStringArray;
}