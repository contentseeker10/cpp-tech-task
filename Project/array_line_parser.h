/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* Project
*/

#pragma once

#include <vector>
#include <string>

using StrVec = std::vector<std::string>;
using IntVec = std::vector<int>;

StrVec getstrv(const std::string& line, const std::string& delims);
IntVec getintv(const StrVec& strv);