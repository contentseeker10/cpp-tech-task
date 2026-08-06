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

#include "csorter.h"
#include "cintersector.h"
#include "cunifier.h"

template <typename T, typename... Args>
class ArrayTransformer {
public:
	virtual ~ArrayTransformer() = default;
	virtual void op(T& arr, const Args&... args) = 0;
};

template <typename T, typename... Args>
class ArraySorter : public ArrayTransformer<T, Args...> {
public:
	void op(T& arr, const Args&... args) override {
		custom::sort(arr.begin(), arr.end());
	}
};

template <typename T, typename... Args>
class ArrayReverseSorter : public ArrayTransformer<T, Args...> {
public:
	void op(T& arr, const Args&... args) override {
		custom::sort(arr.rbegin(), arr.rend());
	}
};

template <typename T, typename... Args>
class ArrayIntersector : public ArrayTransformer<T, Args...> {
public:
	void op(T& arr, const Args&... args) override {
		custom::intersect(arr, args...);
	}
};

template <typename T, typename... Args>
class ArrayUnifier : public ArrayTransformer<T, Args...> {
public:
	void op(T& arr, const Args&... args) override {
		custom::unite(arr, args...);
	}
};