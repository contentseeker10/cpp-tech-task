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

template <typename T, typename... Args>
class ArrayTransformer {
public:
	virtual ~ArrayTransformer() = default;
	virtual void op(T& arr, Args&... args) = 0;
};

template <typename T>
void sort_one(T& c) {
	custom::sort(c.begin(), c.end());
}
template <typename T, typename... Args>
class ArraySorter : public ArrayTransformer<T, Args...> {
public:
	void op(T& arr, Args&... args) override {
		custom::sort(arr.begin(), arr.end());
		int i[] = { 0, (sort_one(args), 0)... };
	}
};

template <typename T>
void rsort_one(T& c) {
	custom::sort(c.rbegin(), c.rend());
}
template <typename T, typename... Args>
class ArrayReverseSorter : public ArrayTransformer<T, Args...> {
public:
	void op(T& arr, Args&... args) override {
		custom::sort(arr.rbegin(), arr.rend());
		int i[] = { 0, (rsort_one(args), 0)... };
	}
};

template <typename T, typename... Args>
class ArrayIntersector : public ArrayTransformer<T, Args...> {
public:
	void op(T& arr, Args&... args) override {
		custom::intersect(arr, args...);
	}
};

template <typename T, typename... Args>
class ArrayUnifier : public ArrayTransformer<T, Args...> {
public:
	void op(T& arr, Args&... args) override {
		custom::unite(arr, args...);
	}
};