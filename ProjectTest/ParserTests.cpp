/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* ProjectTest
*
* ParserTests.cpp
*/

#include "pch.h"

TEST(Parser, Fills_StringVector_Successfully) {
	std::string test_data = "10 20 30\n15 25 35\n100 200 300";
	StrVec v{ getstrc<StrVec>(test_data, ", ") };
	ASSERT_FALSE(v.empty());
}

TEST(Parser, Fills_IntegerVector_Successfully) {
	std::string test_data = "10 20 30\n15 25 35\n100 200 300";
	StrVec strv{ getstrc<StrVec>(test_data, ", ") };
	IntVec intv{ getintc<IntVec, StrVec>(strv) };
	ASSERT_FALSE(intv.empty());
}

TEST(Parser, Fills_Container_Successfully) {
	std::string test_data = "10 20 30\n15 25 35\n100 200 300";
	std::list<std::string> strl{ getstrc<std::list<std::string>>(test_data, ", ") };
	std::list<int> inta{ getintc<std::list<int>>(strl) };
	ASSERT_FALSE(inta.empty());
}