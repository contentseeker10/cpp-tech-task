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
#include <fstream>
#include <string>
#include <vector>
#include <array>

#include "lparser.h"
#include "cprinter.h"
#include "ArrayTransformerFactory.h"
#include "ArrayTransformer.h"

using std::cin;
using std::cout;
using std::endl;

using IntVec = std::vector<int>;

std::array<IntVec, 3> load_data(std::ifstream& file) {
    using StrVec = std::vector<std::string>;

    IntVec v1;
    IntVec v2;
    IntVec v3;

    std::array<IntVec, 3> data_matrix{ v1, v2, v3 };

    std::string line;
    size_t i{};
    while (std::getline(file, line)) {
        data_matrix.at(i) = getintc<IntVec>(getstrc<StrVec>(line, ", "));
        ++i;
    }

    return data_matrix;
}

void test_data(std::array<IntVec, 3> data) {
    for (const auto& c : data) {
        cprint(c);
    }
}

int main() {
	cout << "\n\tC++ Technical Task - by V.Stepanov" << endl;

    const std::vector<std::string> test_files = {
        "testdata/v1.txt",
        "testdata/v2.txt",
        "testdata/v3.txt",
        "testdata/v4.txt"
    };

    for (size_t i = 0; i < test_files.size(); ++i) {
        cout << endl;
        std::ifstream file(test_files[i]);
        if (!file.is_open()) {
            std::cerr << "Could not open file testdata/v" << i + 1 << endl;
            return 1;
        }
        cout << "\tFile #" << i + 1 << endl;
        std::array<IntVec, 3> test_matrix{ load_data(file) };
        test_data(test_matrix);
    }

    cout << endl;
}