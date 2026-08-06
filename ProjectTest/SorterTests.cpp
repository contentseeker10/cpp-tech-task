/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* ProjectTest
*
* SorterTests.cpp
*/

#include "pch.h"

TEST(TransformerSorter, Sorts_Ascending_Successfully) {
	IntVec actual{ 5, 6, 1, 2 };
	IntVec actual2{ 3, 1, 2 };

	IntVec expected{ 1, 2, 5, 6 };
	IntVec expected2{ 1, 2, 3 };

	auto f = make_factory<ArraySorterFactory>(actual, actual2);
	auto t = f->create();

	t->op(actual, actual2);

	EXPECT_EQ(actual, expected);
	EXPECT_EQ(actual2, expected2);
}

TEST(TransformerSorter, Sorts_Descending_Successfully) {
	IntVec actual{ 5, 6, 1, 2 };
	IntVec actual2{ 3, 1, 2 };

	IntVec expected{ 6, 5, 2, 1 };
	IntVec expected2{ 3, 2, 1 };

	auto f = make_factory<ArrayReverseSorterFactory>(actual, actual2);
	auto t = f->create();

	t->op(actual, actual2);

	EXPECT_EQ(actual, expected);
	EXPECT_EQ(actual2, expected2);
}