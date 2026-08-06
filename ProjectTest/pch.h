/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* Project
* 
* pch.h
*/

#pragma once

#include "gtest/gtest.h"

#include "utils/lparser.h"
#include "ArrayTransformer/ArrayTransformer.h"
#include "ArrayTransformer/ArrayTransformerFactory.h"


using StrVec = std::vector<std::string>;
using IntVec = std::vector<int>;

template <typename T, typename... Args>
using Fac = std::unique_ptr<ArrayTransformerFactory<T, Args...>>;