/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* ProjectTest
* 
* test.cpp
*/

#include "pch.h"

#include <list>
#include <set>

using StrVec = std::vector<std::string>;
using IntVec = std::vector<int>;

template <typename T, typename... Args>
using Fac = std::unique_ptr<ArrayTransformerFactory<T, Args...>>;

TEST(Parser, Fills_StringVector_Successfully) {
	std::string test_data = "10 20 30\n15 25 35\n100 200 300";
	StrVec v{ getstrc<StrVec>(test_data, ", ")};
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

TEST(TransformerFactory, Creates_Transformer_Successfully) {
	Fac<IntVec> f(new ArraySorterFactory<IntVec>);
	EXPECT_NE(f, nullptr);
	auto t = f->create();
	EXPECT_NE(t, nullptr);
}

TEST(TransformerSorter, Sorts_Ascending_Successfully) {
	IntVec actual{ 5, 6, 1, 2 };
	IntVec expected{ 1, 2, 5, 6 };

	auto f = make_factory<ArraySorterFactory>(actual);
	auto t = f->create();

	t->op(actual);

	EXPECT_EQ(actual, expected);
}

TEST(TransformerSorter, Sorts_Descending_Successfully) {
	IntVec actual{ 5, 6, 1, 2 };
	IntVec expected{ 6, 5, 2, 1 };

	auto f = make_factory<ArrayReverseSorterFactory>(actual);
	auto t = f->create();

	t->op(actual);

	EXPECT_EQ(actual, expected);
}

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

TEST(TransformerUnifier, Gets_VectorsUnion_Correctly) {
	IntVec v1{ 1, 2, 3, 4 };
	IntVec v2{ 5, 6, 7 };
	IntVec v3{ 8, 9 };
	IntVec expected{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	auto f = make_factory<ArrayUnifierFactory>(v1, v2, v3);
	auto t = f->create();

	t->op(v1, v2, v3);

	EXPECT_EQ(v1, expected);
}

TEST(TransformerUnifier, Gets_ContainersUnion_Correctly) {
	std::vector<int> c1{ 1, 2, 3, 4 };
	std::list<int> c2{ 5, 6, 7 };
	std::set<int> c3{ 8, 9 };
	IntVec expected{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	auto f = make_factory<ArrayUnifierFactory>(c1, c2, c3);
	auto t = f->create();

	t->op(c1, c2, c3);

	EXPECT_EQ(c1, expected);
}

TEST(TransformerUnifier, Gets_UniqueElementsContainer_Correctly) {
	std::vector<int> c1{ 1, 1, 1, 1 };
	std::list<int> c2{ 5, 6, 7 };
	std::set<int> c3{ 6, 9 };
	IntVec expected{ 1, 5, 6, 7, 9 };

	auto f = make_factory<ArrayUnifierFactory>(c1, c2, c3);
	auto t = f->create();

	t->op(c1, c2, c3);

	EXPECT_EQ(
		std::multiset<int>(c1.begin(), c1.end()),
		std::multiset<int>(expected.begin(), expected.end())
    );
}