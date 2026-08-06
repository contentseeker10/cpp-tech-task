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
#include <iomanip>
#include <string>

using std::cout;
using std::endl;

/// @brief Prints container elements in formatted, column-aligned output.
/// @tparam T Container type.
/// @param con Container instance to print.
template <typename T>
void cprint(const T& con) {
    std::cout << "\t[";
    bool first = true;
    for (const auto& e : con) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << std::setw(5) << e;
        first = false;
    }
    std::cout << "]\n";
}