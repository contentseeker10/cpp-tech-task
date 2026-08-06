/*
* Copyright Volodymyr "contentseeker10" Stepanov
* August 2026
*
* cpp-tech-task
* Project
*
* ArrayTransformerFactory.h
*/

#pragma once

#include <memory>

template <typename T>
using ptr = std::unique_ptr<ArrayTransformer<T>>;

#include "ArrayTransformer.h"

template <typename T>
class ArrayTransformerFactory
{
public:
	virtual ~ArrayTransformerFactory() = default;
	virtual ptr<T> create() = 0;
};

template <typename T>
class ArraySorterFactory : public ArrayTransformerFactory<T> {
	ptr<T> create() override {
		return ptr<T>(new ArraySorter<T>());
	}
};

template <typename T>
class ArrayReverseSorterFactory : public ArrayTransformerFactory<T> {
	ptr<T> create() override {
		return ptr<T>(new ArrayReverseSorter<T>());
	}
};

template <typename T>
class ArrayIntersectorFactory : public ArrayTransformerFactory<T> {
	ptr<T> create() override {
		return ptr<T>(new ArrayIntersector<T>());
	}
};

template <typename T>
class ArrayUnifierFactory : public ArrayTransformerFactory<T> {
	ptr<T> create() override {
		return ptr<T>(new ArrayUnifier<T>());
	}
};

template <typename T>
class ArrayFilterFactory : public ArrayTransformerFactory<T> {
	ptr<T> create() override {
		return ptr<T>(new ArrayFilter<T>());
	}
};