/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* ProjectTest
*
* IntersectorTests.cpp
*/

#include "pch.h"

TEST(TransformerIntersector, Gets_VectorsIntersection_Correctly) {
	IntVec v1{ 1, 2, 3, 4, 5 };
	IntVec v2{ 2, 3, 4 };
	IntVec v3{ 3, 4, 5 };
	IntVec expected{ 3, 4 };

	auto f = make_factory<ArrayIntersectorFactory>(v1, v2, v3);
	auto t = f->create();

	t->op(v1, v2, v3);

	EXPECT_EQ(v1, expected);
}

TEST(TransformerIntersector, Gets_ContainersIntersection_Correctly) {
	std::vector<int> c1{ 1, 2, 3, 4, 5 };
	std::list<int> c2{ 2, 3, 4 };
	std::set<int> c3{ 3, 4, 5 };
	IntVec expected{ 3, 4 };

	auto f = make_factory<ArrayIntersectorFactory>(c1, c2, c3);
	auto t = f->create();

	t->op(c1, c2, c3);

	EXPECT_EQ(c1, expected);
}