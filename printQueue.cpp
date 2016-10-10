#include <iostream>
#include <queue>

using namespace std;

template <typename T>
void printQueue(queue<T> queueToBePrinted)
{
    while(!queueToBePrinted.empty())
    {
       cout << queueToBePrinted.top() << endl;
       queueToBePrinted.pop();
    }
 
