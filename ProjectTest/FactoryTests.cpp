/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* ProjectTest
*
* FactoryTests.cpp
*/

#include "pch.h"

TEST(TransformerFactory, Creates_Transformer_Successfully) {
	Fac<IntVec> f(new ArraySorterFactory<IntVec>);
	EXPECT_NE(f, nullptr);
	auto t = f->create();
	EXPECT_NE(t, nullptr);
}