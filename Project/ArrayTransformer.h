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

template <typename T, typename... Args>
class ArrayTransformer {
public:
	virtual ~ArrayTransformer() = default;
	virtual void op(T& arr, Args... args) = 0;
};

template <typename T, typename... Args>
class ArraySorter : public ArrayTransformer<T> {
public:
	void op(T& arr, Args... args) override {
		custom::sort(arr.begin(), arr.end());
	}
};

template <typename T, typename... Args>
class ArrayReverseSorter : public ArrayTransformer<T> {
public:
	void op(T& arr, Args... args) override {
		custom::sort(arr.rbegin(), arr.rend());
	}
};

template <typename T, typename... Args>
class ArrayIntersector : public ArrayTransformer<T> {
public:
	void op(T& arr, Args... args) override {

	}
};

template <typename T, typename... Args>
class ArrayUnifier : public ArrayTransformer<T> {
public:
	void op(T& arr, Args... args) override {

	}
};

template <typename T, typename... Args>
class ArrayFilter : public ArrayTransformer<T> {
public:
	void op(T& arr, Args... args) override {

	}
};