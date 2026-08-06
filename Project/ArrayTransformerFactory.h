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

#include "ArrayTransformer.h"

template <typename T, typename... Args>
using ptr = std::unique_ptr<ArrayTransformer<T, Args...>>;

template <typename T, typename... Args>
class ArrayTransformerFactory
{
public:
	virtual ~ArrayTransformerFactory() = default;
	virtual ptr<T, Args...> create() = 0;
};

template <typename T, typename... Args>
class ArraySorterFactory : public ArrayTransformerFactory<T, Args...> {
	ptr<T, Args...> create() override {
		return ptr<T, Args...>(new ArraySorter<T, Args...>());
	}
};

template <typename T, typename... Args>
class ArrayReverseSorterFactory : public ArrayTransformerFactory<T, Args...> {
	ptr<T, Args...> create() override {
		return ptr<T, Args...>(new ArrayReverseSorter<T, Args...>());
	}
};

template <typename T, typename... Args>
class ArrayIntersectorFactory : public ArrayTransformerFactory<T, Args...> {
	ptr<T, Args...> create() override {
		return ptr<T, Args...>(new ArrayIntersector<T, Args...>());
	}
};

template <typename T, typename... Args>
class ArrayUnifierFactory : public ArrayTransformerFactory<T, Args...> {
	ptr<T, Args...> create() override {
		return ptr<T, Args...>(new ArrayUnifier<T, Args...>());
	}
};

template <typename T, typename... Args>
class ArrayFilterUniqueFactory : public ArrayTransformerFactory<T, Args...> {
	ptr<T, Args...> create() override {
		return ptr<T, Args...>(new ArrayFilter<T, Args...>());
	}
};

template <typename T, typename... Args>
using TrFac = ArrayTransformerFactory<T, Args...>;

template <template <typename, typename...> class Factory, typename T, typename... Args>
std::unique_ptr<TrFac<T, Args...>> make_factory(const T&, const Args&...) {
	return std::unique_ptr<TrFac<T, Args...>>(new Factory<T, Args...>());
}