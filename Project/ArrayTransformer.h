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

template <typename T>
class ArrayTransformer {
public:
	virtual ~ArrayTransformer() = default;
	virtual void op(T& arr) = 0;
};

template <typename T>
class ArraySorter : public ArrayTransformer<T> {
public:
	void op(T& arr) override {
		custom::sort(arr, arr.begin(), arr.end());
	}
};

template <typename T>
class ArrayReverseSorter : public ArrayTransformer<T> {
public:
	void op(T& arr) override {

	}
};

template <typename T>
class ArrayIntersector : public ArrayTransformer<T> {
public:
	void op(T& arr) override {

	}
};

template <typename T>
class ArrayUnifier : public ArrayTransformer<T> {
public:
	void op(T& arr) override {

	}
};

template <typename T>
class ArrayFilter : public ArrayTransformer<T> {
public:
	void op(T& arr) override {

	}
};