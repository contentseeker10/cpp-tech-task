/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* Project
*/

#include <stdexcept>
#include <type_traits>
#include <string>

template<typename T>
T getstrv(const std::string& line, const std::string& delims) {
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

template <typename T>
struct is_string_container : std::false_type {};

template <template <typename...> class C, typename... Args>
struct is_string_container<C<std::string, Args...>> : std::true_type {};

template <typename T, typename C, typename = typename std::enable_if<is_string_container<C>::value>::type>
T getintv(const C& strc) {
	T res;
	res.reserve(strc.size());

	for (const auto& e : strc) {
		auto val = std::stoi(e);
		res.push_back(val);
	}

	return res;
}