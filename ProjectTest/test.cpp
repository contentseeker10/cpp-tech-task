#include "pch.h"

using StrVec = std::vector<std::string>;
using IntVec = std::vector<int>;
TEST(Parser, Fills_StringVector_Successfully) {
	std::string test_data = "10 20 30\n15 25 35\n100 200 300";
	StrVec v{ getstrv<StrVec>(test_data, ", ")};
	EXPECT_FALSE(v.empty());
}

TEST(Parser, Fills_IntegerVector_Successfully) {
	std::string test_data = "10 20 30\n15 25 35\n100 200 300";
	StrVec strv{ getstrv<StrVec>(test_data, ", ") };
	IntVec intv{ getintv<IntVec, StrVec>(strv) };
	EXPECT_FALSE(intv.empty());
}