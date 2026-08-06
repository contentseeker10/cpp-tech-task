/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
* 
* cpp-tech-task
* Project
* 
* main.cpp
*/

#include <iostream>
#include <vector>

#include "lparser.h"
#include "cprinter.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
	cout << "\nC++ Technical Task - by V.Stepanov\n" << endl;

	std::vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	print(v);
}