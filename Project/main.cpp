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

void print_data(std::array<IntVec, 3>& data) {
    for (const auto& c : data) {
        cprint(c);
    }
}

void test_sorter(IntVec& v1, IntVec& v2, IntVec& v3) {
    auto fac = make_factory<ArraySorterFactory>(v1, v2, v3);
    auto sorter = fac->create();
    sorter->op(v1, v2, v3);
    cout << "\n\tArrays after ascending sorting:" << endl;
}

void test_rsorter(IntVec& v1, IntVec& v2, IntVec& v3) {
    auto fac = make_factory<ArrayReverseSorterFactory>(v1, v2, v3);
    auto rsorter = fac->create();
    rsorter->op(v1, v2, v3);
    cout << "\n\tArrays after descending sorting:" << endl;
}

void test_intersector(IntVec& v1, IntVec& v2, IntVec& v3) {
    auto fac = make_factory<ArrayIntersectorFactory>(v1, v2, v3);
    auto intersector = fac->create();
    intersector->op(v1, v2, v3);
    cout << "\n\tAll Arrays Intersection result:" << endl;
}
void test_intersector(IntVec& v1, IntVec& v2) {
    auto fac = make_factory<ArrayIntersectorFactory>(v1, v2);
    auto intersector = fac->create();
    intersector->op(v1, v2);
    cout << "\n\tTwo Largest Arrays Intersection result:" << endl;
}

void test_unifier(IntVec& v1, IntVec& v2, IntVec& v3) {
    auto fac = make_factory<ArrayUnifierFactory>(v1, v2, v3);
    auto unifier = fac->create();
    unifier->op(v1, v2, v3);
    cout << "\n\tAll Arrays Unity result:" << endl;
}

void test_data(std::array<IntVec, 3>& data) {
    print_data(data);

    IntVec& v1 = data.at(0);
    IntVec& v2 = data.at(1);
    IntVec& v3 = data.at(2);

    test_sorter(v1, v2, v3);
    print_data(data);

    test_rsorter(v1, v2, v3);
    print_data(data);

    std::vector<IntVec*> ptrs = { &v1, &v2, &v3 };
    std::sort(ptrs.begin(), ptrs.end(), [](IntVec* a, IntVec* b) { return a->size() > b->size(); });
    IntVec result = *ptrs[0];
    test_intersector(result, *ptrs[1]);
    cprint(result);

    result = v1;
    test_intersector(result, v2, v3);
    cprint(result);

    result = v1;
    test_unifier(result, v2, v3);
    cprint(result);

    cout << "\n\tAll Arrays Unity Reversed Sort result:" << endl;
    auto fac = make_factory<ArrayReverseSorterFactory>(result);
    auto rsorter = fac->create();
    rsorter->op(result);
    cprint(result);
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
        cout << "\n---\n" << endl;
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