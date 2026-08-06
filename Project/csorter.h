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
	template <typename T>
	void swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

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

	template <typename It>
	void sort(It begin, It end) {
		if (begin < end) {
			It p = custom::partition(begin, end);
			custom::sort(begin, p);
			custom::sort(p + 1, end);
		}
	}
}
