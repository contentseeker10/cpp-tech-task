/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* Project
*
* ArrayTransformer.h
*/

#pragma once

#include "utils/csorter.h"
#include "utils/cintersector.h"
#include "utils/cunifier.h"

/// @brief Abstract base class for container transformation operations.
/// @tparam T Primary container type.
/// @tparam Args Additional variadic container types.
template <typename T, typename... Args>
class ArrayTransformer {
public:
	virtual ~ArrayTransformer() = default;

	/// @brief Applies transformation operation in-place.
	/// @param[in,out] arr Primary target container.
	/// @param[in,out] args Additional containers.
	virtual void op(T& arr, Args&... args) = 0;
};

/// @brief Helper function to sort a single container in ascending order.
template <typename T>
void sort_one(T& c) {
	custom::sort(c.begin(), c.end());
}

/// @brief Concrete transformer sorting containers in ascending order.
template <typename T, typename... Args>
class ArraySorter : public ArrayTransformer<T, Args...> {
public:
	void op(T& arr, Args&... args) override {
		custom::sort(arr.begin(), arr.end());
		int i[] = { 0, (sort_one(args), 0)... };
		(void)i;
	}
};

/// @brief Helper function to sort a single container in descending order.
template <typename T>
void rsort_one(T& c) {
	custom::sort(c.rbegin(), c.rend());
}

/// @brief Concrete transformer sorting containers in descending order.
template <typename T, typename... Args>
class ArrayReverseSorter : public ArrayTransformer<T, Args...> {
public:
	void op(T& arr, Args&... args) override {
		custom::sort(arr.rbegin(), arr.rend());
		int i[] = { 0, (rsort_one(args), 0)... };
		(void)i;
	}
};

/// @brief Concrete transformer computing the intersection of containers in-place.
template <typename T, typename... Args>
class ArrayIntersector : public ArrayTransformer<T, Args...> {
public:
	void op(T& arr, Args&... args) override {
		custom::intersect(arr, args...);
	}
};

/// @brief Concrete transformer computing the union of containers in-place.
template <typename T, typename... Args>
class ArrayUnifier : public ArrayTransformer<T, Args...> {
public:
	void op(T& arr, Args&... args) override {
		custom::unite(arr, args...);
	}
};