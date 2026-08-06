# C++ Technical Task

A C++ project for parsing, sorting, intersecting, and unifying numeric container sequences using template metaprogramming, modern C++ patterns, and Google Test.

## Features

- **String & Container Parsing**: Generic parsing routines (`getstrc`, `getintc`) with delimiter handling and container traits (`is_string_container`).
- **Custom Algorithms**:
  - **QuickSort**: In-place sorting with Lomuto partitioning for random-access iterators (`csorter.h`).
  - **Intersection**: In-place multi-container filtering (`cintersector.h`).
  - **Union**: In-place unique element unification (`cunifier.h`).
- **Design Patterns**: Polymorphic `ArrayTransformer` hierarchy combined with `AbstractFactory` and type-deduced `make_factory` helpers.
- **Unit Testing**: Modular Google Test suite structured by test cases (`ParserTests`, `SorterTests`, `IntersectorTests`, `UnifierTests`, `FactoryTests`).

## Project Structure

```text
cpp-tech-task/
├── Project/
│   ├── ArrayTransformer/       # Polymorphic interfaces and factory classes
│   ├── utils/                  # Core algorithms (sorting, intersecting, unifying, parsing, printing)
│   ├── testdata/               # Sample input test datasets
│   └── main.cpp                # Main application entry point
└── ProjectTest/                # Google Test suite divided by test cases
```

## Requirements & Building

- **Language Standard**: C++11
- **Compiler**: MSVC (Visual Studio 2022 / 2026) or compatible C++ compiler
- **Test Framework**: Google Test (gtest)

### Building via MSBuild

```bash
# Build the test suite
msbuild ProjectTest/ProjectTest.vcxproj -p:Configuration=Debug -p:Platform=x64

# Run unit tests
./ProjectTest/x64/Debug/ProjectTest.exe
```

## License

Copyright (c) 2026 Volodymyr Stepanov. All rights reserved.