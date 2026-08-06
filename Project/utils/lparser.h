/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* Project
* 
* line_parser.h
*/

#pragma once

#include <type_traits>
#include <string>

/// @brief Splits a string into tokens based on specified delimiters.
/// @tparam T Target container type (e.g., std::vector<std::string>).
/// @param line Source string to parse.
/// @param delims String of delimiter characters.
/// @return Container T populated with extracted string tokens.
template<typename T>
T getstrc(const std::string& line, const std::string& delims) {
	T tokens;
	size_t begin = line.find_first_not_of(delims);
	size_t end = line.find_first_of(delims, begin);

	while (begin != std::string::npos) {
		tokens.push_back(line.substr(begin, end - begin));
		begin = line.find_first_not_of(delims, end);
		end = line.find_first_of(delims, begin);
	}

	return tokens;
}

/// @brief Conditionally reserves capacity if container T supports .reserve().
template <typename T>
auto reserve_if_possible(T& container, std::size_t size) -> decltype(container.reserve(size), void()) {
	container.reserve(size);
}
inline void reserve_if_possible(...) {}

/// @brief Type trait checking if C is a container holding std::string.
template <typename T>
struct is_string_container : std::false_type {};

template <template <typename...> class C, typename... Args>
struct is_string_container<C<std::string, Args...>> : std::true_type {};

/// @brief Converts a string container to an integer container.
/// @tparam T Target integer container type (e.g., std::vector<int>).
/// @tparam C Source string container type.
/// @param strc Input string container.
/// @return Container T filled with converted integers.
template <typename T, typename C, typename = typename std::enable_if<is_string_container<C>::value>::type>
T getintc(const C& strc) {
	T res;
	reserve_if_possible(res, strc.size());

	for (const auto& e : strc) {
		auto val = std::stoi(e);
		res.push_back(val);
	}

	return res;
}