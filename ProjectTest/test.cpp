#include "pch.h"

#include <list>
#include <array>

using StrVec = std::vector<std::string>;
using IntVec = std::vector<int>;

TEST(Parser, Fills_StringVector_Successfully) {
	std::string test_data = "10 20 30\n15 25 35\n100 200 300";
	StrVec v{ getstrc<StrVec>(test_data, ", ")};
	EXPECT_FALSE(v.empty());
}

TEST(Parser, Fills_IntegerVector_Successfully) {
	std::string test_data = "10 20 30\n15 25 35\n100 200 300";
	StrVec strv{ getstrc<StrVec>(test_data, ", ") };
	IntVec intv{ getintc<IntVec, StrVec>(strv) };
	EXPECT_FALSE(intv.empty());
}

TEST(Parser, Fills_Container_Successfully) {
	std::string test_data = "10 20 30\n15 25 35\n100 200 300";
	std::list<std::string> strl{ getstrc<std::list<std::string>>(test_data, ", ") };
	std::list<int> inta{ getintc<std::list<int>>(strl) };
	EXPECT_FALSE(inta.empty());
}