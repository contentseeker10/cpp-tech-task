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
	/// @brief Conditionally reserves capacity if container T supports .reserve().
	template <typename T>
	auto reserve_if_possible(T& cont, size_t size) -> decltype(cont.reserve(size), void()) {
		cont.reserve(size);
	}
	inline void reserve_if_possible(...) {}

	/// @brief Unites container 'b' into container 'a', preserving unique elements.
	/// @tparam T1 Target container type.
	/// @tparam T2 Source container type.
	/// @param[in,out] a Target container updated with elements from b.
	/// @param[in] b Source container.
	template <typename T1, typename T2>
	void unpack_unite(T1& a, T2& b) {
		std::unordered_set<typename T1::value_type> set(a.begin(), a.end());
		set.insert(b.begin(), b.end());
		a.assign(set.begin(), set.end());
	}

	/// @brief Computes in-place union of primary container 'cont' with multiple containers.
	/// @tparam T Primary target container type.
	/// @tparam Args Additional container types.
	/// @param[in,out] cont Primary container updated with unified elements.
	/// @param[in] args Variadic parameter pack of containers to unite.
	template <typename T, typename... Args>
	void unite(T& cont, const Args&... args) {
		int i[] = { 0, (unpack_unite(cont, args), 0)... };
		(void)i;
	}
}