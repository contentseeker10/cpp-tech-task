/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* Project
* 
* cprinter.h
*/

#pragma once

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
void print(const T& con) {
	cout << "{ ";
	for (const auto& e : con) {
		cout << e << ' ';
	}
	cout << "}" << endl;
}