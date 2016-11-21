#pragma once

#include <iostream>
#include "findTab.h"

void errorBlock(std::string errorMessage);
void headBlock(std::string nextSymbol);
void logicBlock(std::string nextSymbol);
void statementBlock(std::string nextSymbol);
void expresionBlock(std::string nextSymbol);
void termBlock(std::string nextSymbol);
void factorBlock(std::string nextSymbol);
void syntaxAnalize(std::queue<int> list);