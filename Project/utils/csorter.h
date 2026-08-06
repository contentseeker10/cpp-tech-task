/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* ProjectTest
*
* csorter.h
*/

#pragma once

#include <iterator>

namespace custom {
	/// @brief Swaps two values by reference.
	template <typename T>
	void swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

	/// @brief Lomuto partition scheme for QuickSort.
	/// @tparam It Random access iterator type.
	/// @param begin Iterator to start of range.
	/// @param end Iterator to end of range.
	/// @return Iterator to the pivot position after partitioning.
	template <typename It>
	It partition(It begin, It end) {
		auto pivot = *(end - 1);
		It i = begin;

		for (It j = begin; j < end - 1; ++j) {
			if (*j <= pivot) {
				swap(*i, *j);
				++i;
			}
		}
		swap(*i, *(end - 1));
		return i;
	}

	/// @brief In-place QuickSort algorithm for random access iterator ranges.
	/// @tparam It Random access iterator type.
	/// @param begin Iterator to start of range.
	/// @param end Iterator to end of range.
	template <typename It>
	void sort(It begin, It end) {
		if (begin < end) {
			It p = custom::partition(begin, end);
			custom::sort(begin, p);
			custom::sort(p + 1, end);
		}
	}
}
