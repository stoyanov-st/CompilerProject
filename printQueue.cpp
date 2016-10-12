#include <iostream>
#include <queue>

using namespace std;
#include "../ep/EP-2/EP-2/printQueue.h"
void printQueue(queue<int> queueToBePrinted)
{
	while (!queueToBePrinted.empty())
	{
		cout << queueToBePrinted.front() << endl;
		queueToBePrinted.pop();
	}
}