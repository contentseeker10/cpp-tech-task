/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* Project
*/

#include <stdexcept>

#include "array_line_parser.h"

StrVec getstrv(const std::string& line, const std::string& delims) {
	StrVec tokens;
	size_t begin = line.find_first_not_of(delims);
	size_t end = line.find_first_of(delims, begin);

	while (begin != std::string::npos) {
		tokens.push_back(line.substr(begin, end - begin));
		begin = line.find_first_not_of(delims, end);
		end = line.find_first_of(delims, begin);
	}

	return tokens;
}

IntVec getintv(const StrVec& strv) {
	IntVec res;
	res.reserve(strv.size());

	for (const auto& e : strv) {
		if (auto val = std::stoi(e)) {
			res.push_back(val);
		}
		else {
			throw std::invalid_argument("Invalid argument");
		}
	}

	return res;
}