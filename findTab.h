#pragma once

#include "printQueue.h"
#include <iostream>
#include <vector>
#include <regex>
#include <queue>
#include <string>

extern std::queue<int> positionList;
extern std::vector<std::pair<std::string, int>> symbolTable;

int findTab(std::string sym, int attr);
void fillTable();
void lexicalAnalyze(std::string inputString);