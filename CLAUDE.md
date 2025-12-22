# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a C++ learning project for data structures and algorithms implementation. The project is primarily designed for educational purposes, suitable for both beginners and advanced learners who want to review and consolidate fundamental knowledge.

## Build and Development Environment

- **Compiler**: Visual Studio 2022/2026 or compatible C++ development environment
- **Language**: C++20 (primary), with C++11 support for some configurations
- **Project Format**: Visual Studio project file (.vcxproj) located in the subdirectory
- **Platforms**: Supports both Win32 (x86) and x64 architectures
- **External Dependencies**: Ctoon library (optional, referenced but not required for core functionality)

### Common Commands

```bash
# Compile and run individual files (from project root)
g++ -std=c++20 "data structures and algorithms/data structures and algorithms.cpp" -o main && ./main
g++ -std=c++20 "data structures and algorithms/linked list.cpp" -o linked_list && ./linked_list
g++ -std=c++20 "data structures and algorithms/数组的增删改查.cpp" -o array_ops && ./array_ops
g++ -std=c++20 "data structures and algorithms/复盘.cpp" -o review && ./review
g++ -std=c++20 "data structures and algorithms/单链表逆序.cpp" -o reverse && ./reverse

# Run with Visual Studio
# Open "data structures and algorithms/data structures and algorithms.vcxproj"
# Use F5 to build and run
# Build configurations available: Debug/Release for both Win32 and x64

# Test specific sections by modifying #if 0/#if 1 flags in the source files
```

## Code Architecture

### Main Components

1. **Array Implementation** (`data structures and algorithms.cpp`)
   - Basic array operations (insert, delete, search, reverse)
   - Dynamic Array class with automatic capacity expansion
   - Demonstrates O(1) amortized push_back, O(n) insert/erase operations

2. **Linked List Implementation** (`linked list.cpp`)
   - Singly linked list with head node
   - Operations: insertHead, insertTail, remove, reverse, find
   - Friend functions for merging sorted lists and finding kth node from end

3. **Vector Template Class** (`vector.cpp`)
   - Complete STL-like vector implementation (commented out)
   - Template-based design supporting any data type
   - Full iterator support for range-based for loops

### Code Structure Patterns

- **Learning-Oriented Design**: Code contains extensive Chinese comments explaining concepts
- **Progressive Complexity**: Starts with basic array operations, moves to complex data structures
- **Multiple Implementation Examples**: Different approaches to the same problem (e.g., array reverse using different pointer techniques)
- **Conditional Compilation**: Uses `#if 0` blocks to enable/disable different sections for testing

### Key Files

- `data structures and algorithms/data structures and algorithms.cpp`: Main file with array operations and dynamic array class
- `data structures and algorithms/linked list.cpp`: Complete linked list implementation with friend functions, circular detection, and reversal
- `data structures and algorithms/vector.cpp`: Template-based vector implementation (educational, commented out)
- `data structures and algorithms/数组的增删改查.cpp`: Basic array CRUD operations in Chinese
- `data structures and algorithms/单链表逆序.cpp`: Linked list reversal exercises
- `data structures and algorithms/复盘.cpp`: Comprehensive review and summary exercises with various operations
- `data structures and algorithms/复盘单链表.cpp`: Additional linked list review exercises
- `data structures and algorithms/[1-3].cpp`: Additional coding exercise files
- `data structures and algorithms/data structures and algorithms.vcxproj`: Visual Studio project file with all source files included

## Development Guidelines

### Testing Approach

- Use conditional compilation (`#if 0`/`#if 1`) to test different sections
- Each main() function contains multiple test scenarios
- Random number generation for creating test data

### Code Style

- Chinese comments for educational clarity
- Clear separation between interface and implementation
- Memory management with explicit delete operations
- Proper use of pointers and references

### Adding New Implementations

When adding new data structures or algorithms:
1. Create a new .cpp file in the `data structures and algorithms/` subdirectory
2. Follow the existing pattern with clear Chinese comments for educational purposes
3. Include comprehensive test cases in main() using conditional compilation (`#if 0`/`#if 1`)
4. Add the new file to the Visual Studio project file (`data structures and algorithms.vcxproj`) if using IDE builds
5. Use consistent naming conventions (prefer Chinese filenames for educational content)

### Testing and Code Activation

Most files contain multiple sections controlled by `#if 0`/`#if 1` preprocessor directives:
- To test specific functionality, change `#if 0` to `#if 1` for the desired section
- Each file typically has a main() function with different test scenarios
- Common pattern: multiple implementations of the same algorithm with different approaches

### Project Structure Notes

- **Source Organization**: All implementation files are located in the `data structures and algorithms/` subdirectory
- **Visual Studio Integration**: The `.vcxproj` file includes all source files for IDE builds
- **Bilingual Content**: Mix of English and Chinese filenames and comments for learning purposes
- **Optional Dependencies**: Ctoon library headers are referenced but not required for core functionality
- **Multi-platform**: While primarily designed for Windows/Visual Studio, can be compiled with g++ on other platforms
- **Educational Focus**: Code emphasizes clarity and learning over performance optimization
- **Memory Management**: Explicit memory allocation/deletion with proper destructor patterns