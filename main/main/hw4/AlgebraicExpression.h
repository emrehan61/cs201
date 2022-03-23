#pragma once
//Emrehan Hoþver 21903488
#include <iostream>
#include "Stack.h"
#include <string>
std::string infix2prefix(const std::string exp);
std::string infix2postfix(const std::string exp);
std::string prefix2infix(const std::string exp);
std::string prefix2postfix(const std::string exp);
std::string postfix2infix(const std::string exp);
std::string postfix2prefix(const std::string exp);
int priorityalgeb(char c);
std::string rever(std::string s);
bool isOperator(char op);
