#include "pch.h"

TEST(Parser, Fills_StringVector_Successfully) {
	std::string test_data = "10 20 30\n15 25 35\n100 200 300";
	StrVec v{ getstrv(test_data, ", ")};
	EXPECT_FALSE(v.empty());
}

TEST(Parser, Fills_IntegerVector_Successfully) {
	std::string test_data = "10 20 30\n15 25 35\n100 200 300";
	StrVec strv{ getstrv(test_data, ", ") };
	IntVec intv{ getintv(strv) };
	EXPECT_FALSE(intv.empty());
}