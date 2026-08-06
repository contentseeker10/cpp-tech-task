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

/// @brief Smart pointer type alias for ArrayTransformer instances.
template <typename T, typename... Args>
using ptr = std::unique_ptr<ArrayTransformer<T, Args...>>;

/// @brief Abstract factory interface for creating ArrayTransformer instances.
/// @tparam T Primary container type.
/// @tparam Args Additional variadic container types.
template <typename T, typename... Args>
class ArrayTransformerFactory
{
public:
	virtual ~ArrayTransformerFactory() = default;

	/// @brief Creates a unique instance of ArrayTransformer.
	/// @return Unique pointer to the constructed ArrayTransformer.
	virtual ptr<T, Args...> create() = 0;
};

/// @brief Factory creating ArraySorter instances.
template <typename T, typename... Args>
class ArraySorterFactory : public ArrayTransformerFactory<T, Args...> {
	ptr<T, Args...> create() override {
		return ptr<T, Args...>(new ArraySorter<T, Args...>());
	}
};

/// @brief Factory creating ArrayReverseSorter instances.
template <typename T, typename... Args>
class ArrayReverseSorterFactory : public ArrayTransformerFactory<T, Args...> {
	ptr<T, Args...> create() override {
		return ptr<T, Args...>(new ArrayReverseSorter<T, Args...>());
	}
};

/// @brief Factory creating ArrayIntersector instances.
template <typename T, typename... Args>
class ArrayIntersectorFactory : public ArrayTransformerFactory<T, Args...> {
	ptr<T, Args...> create() override {
		return ptr<T, Args...>(new ArrayIntersector<T, Args...>());
	}
};

/// @brief Factory creating ArrayUnifier instances.
template <typename T, typename... Args>
class ArrayUnifierFactory : public ArrayTransformerFactory<T, Args...> {
	ptr<T, Args...> create() override {
		return ptr<T, Args...>(new ArrayUnifier<T, Args...>());
	}
};

/// @brief Alias for ArrayTransformerFactory interface.
template <typename T, typename... Args>
using TrFac = ArrayTransformerFactory<T, Args...>;

/// @brief Helper function creating a factory instance with automatically deduced template types.
/// @tparam Factory Concrete factory template class.
/// @tparam T Primary container type (deduced).
/// @tparam Args Additional container types (deduced).
/// @return Unique pointer to the created factory interface.
template <template <typename, typename...> class Factory, typename T, typename... Args>
std::unique_ptr<TrFac<T, Args...>> make_factory(const T&, const Args&...) {
	return std::unique_ptr<TrFac<T, Args...>>(new Factory<T, Args...>());
}