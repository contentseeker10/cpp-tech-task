/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* Project
*
* cintersector.h
*/

#pragma once

#include <unordered_set>

namespace custom {
	template <typename T1, typename T2>
	void unpack(T1& a, const T2& b) {
		if (a.empty()) return;
		std::unordered_set<typename T1::value_type> uset(b.begin(), b.end());
		a.erase(
			std::remove_if(a.begin(), a.end(),
				[&uset](<const typename C1::value_type& v>) {
					return uset.count(v) == 0;
				}),
			a.end();
		);
	}

	template <typename T, typename... Args>
	void intersect(T& cont, const Args&... args) {
		int i[] = { 0, (unpack(cont, args), 0)... };
	}
}