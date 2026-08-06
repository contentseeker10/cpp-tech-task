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

#include <unordered_map>

namespace custom {
	/// @brief Helper function counting element frequencies in container 'b'.
	template <typename M, typename C>
	void count_elements(M& counts, const C& b) {
		for (const auto& e : b) {
			counts[e]++;
		}
	}

	/// @brief Retains ONLY strictly unique elements (appearing exactly once across all containers).
	/// @tparam T Primary target container type.
	/// @tparam Args Additional container types.
	/// @param[in,out] cont Primary container updated with elements having total frequency == 1.
	/// @param[in] args Variadic parameter pack of containers.
	template <typename T, typename... Args>
	void unite(T& cont, const Args&... args) {
		std::unordered_map<typename T::value_type, int> counts;

		count_elements(counts, cont);

		int i[] = { 0, (count_elements(counts, args), 0)... };
		(void)i;

		cont.clear();
		for (const auto& pair : counts) {
			if (pair.second == 1) {
				cont.insert(cont.end(), pair.first);
			}
		}
	}
}