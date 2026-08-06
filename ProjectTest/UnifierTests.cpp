/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* ProjectTest
*
* UnifierTests.cpp
*/

#include "pch.h"

TEST(TransformerUnifier, Gets_VectorsUnion_Correctly) {
	IntVec v1{ 1, 2, 3, 4 };
	IntVec v2{ 5, 6, 7 };
	IntVec v3{ 8, 9 };
	IntVec expected{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	auto f = make_factory<ArrayUnifierFactory>(v1, v2, v3);
	auto t = f->create();

	t->op(v1, v2, v3);

	EXPECT_EQ(
		std::multiset<int>(v1.begin(), v1.end()),
		std::multiset<int>(expected.begin(), expected.end())
	);
}

TEST(TransformerUnifier, Gets_ContainersUnion_Correctly) {
	std::vector<int> c1{ 1, 2, 3, 4 };
	std::list<int> c2{ 5, 6, 7 };
	std::set<int> c3{ 8, 9 };
	IntVec expected{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	auto f = make_factory<ArrayUnifierFactory>(c1, c2, c3);
	auto t = f->create();

	t->op(c1, c2, c3);

	EXPECT_EQ(
		std::multiset<int>(c1.begin(), c1.end()),
		std::multiset<int>(expected.begin(), expected.end())
	);
}

TEST(TransformerUnifier, Keeps_OnlyStrictlyUniqueElements_Correctly) {
	std::vector<int> c1{ 1, 1, 1, 1 };
	std::list<int> c2{ 5, 6, 7 };
	std::set<int> c3{ 6, 9 };
	IntVec expected{ 5, 7, 9 };

	auto f = make_factory<ArrayUnifierFactory>(c1, c2, c3);
	auto t = f->create();

	t->op(c1, c2, c3);

	EXPECT_EQ(
		std::multiset<int>(c1.begin(), c1.end()),
		std::multiset<int>(expected.begin(), expected.end())
	);
}