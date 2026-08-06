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

#include "ArrayTransformer.h"

template <typename T>
class ArrayTransformerFactory
{
public:
	virtual ~ArrayTransformerFactory() = default;
	virtual ArrayTransformer<T>* create() = 0;
};

template <typename T>
class ArraySorterFactory : public ArrayTransformerFactory<T> {
	ArrayTransformer<T>* create() override {
		return new ArraySorter<T>();
	}
};

template <typename T>
class ArrayReverseSorterFactory : public ArrayTransformerFactory<T> {
	ArrayTransformer<T>* create() override {
		return new ArrayReverseSorter<T>();
	}
};

template <typename T>
class ArrayIntersectorFactory : public ArrayTransformerFactory<T> {
	ArrayTransformer<T>* create() override {
		return new ArrayIntersector<T>();
	}
};

template <typename T>
class ArrayUnifierFactory : public ArrayTransformerFactory<T> {
	ArrayTransformer<T>* create() override {
		return new ArrayUnifier<T>();
	}
};

template <typename T>
class ArrayFilterFactory : public ArrayTransformerFactory<T> {
	ArrayTransformer<T>* create() override {
		return new ArrayFilter<T>();
	}
};