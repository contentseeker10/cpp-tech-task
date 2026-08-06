/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* ProjectTest
*
* cunifier.h
*/

#pragma once

#include <unordered_set>

namespace custom {
	template <typename T>
	auto reserve_if_possible(T& cont, size_t size) -> decltype(cont.reserve(size), void()) {
		cont.reserve(size);
	}
	inline void reserve_if_possible(...) {}

	template <typename T1, typename T2>
	void unpack_unite(T1& a, T2& b) {
		std::unordered_set<typename T1::value_type> set(a.begin(), a.end());
		set.insert(b.begin(), b.end());
		a.assign(set.begin(), set.end());
	}

	template <typename T, typename... Args>
	void unite(T& cont, const Args&... args) {
		int i[] = { 0, (unpack_unite(cont, args), 0)... };
	}
}