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
#include <algorithm>

namespace custom {
	/// @brief Filters container 'a' in-place, keeping only elements present in container 'b'.
	/// @tparam T1 Target container type (modified in-place).
	/// @tparam T2 Source container type.
	/// @param[in,out] a Target container to filter.
	/// @param[in] b Source container to check against.
	template <typename T1, typename T2>
	void unpack(T1& a, const T2& b) {
		if (a.empty()) return;
		std::unordered_set<typename T1::value_type> uset(b.begin(), b.end());
		a.erase(
			std::remove_if(a.begin(), a.end(),
				[&uset](const typename T1::value_type& v) {
					return uset.count(v) == 0;
				}),
			a.end()
		);
	}

	/// @brief Computes in-place intersection of primary container 'cont' with multiple containers.
	/// @tparam T Primary target container type.
	/// @tparam Args Additional container types.
	/// @param[in,out] cont Primary container updated with common elements.
	/// @param[in] args Variadic parameter pack of containers to intersect against.
	template <typename T, typename... Args>
	void intersect(T& cont, const Args&... args) {
		int i[] = { 0, (unpack(cont, args), 0)... };
		(void)i;
	}
}