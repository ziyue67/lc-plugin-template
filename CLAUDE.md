# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

A multi-language LeetCode solutions template repository, primarily focused on C++ implementations. Each problem is a standalone file with its own `main()` function for testing. The project is designed for local practice, teaching demonstrations, and automated evaluation.

## Build and Development Environment

### C++ (Primary)

- **Standard**: C++20
- **Compiler**: g++ or compatible (Visual Studio also supported)
- **Build System**: CMake 3.16+

### Common Commands

```bash
# Compile and run a single problem file (recommended for testing)
g++ -std=c++20 "cpp-template/1.两数之和.cpp" -O2 -Wall -Wextra -o test && ./test

# CMake build - compiles all problems with main() functions
cmake -S cpp-template -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release -- -j

# Run specific executable after CMake build
./build/bin/lc_<hash>

# Other languages
go test ./go-template/...
python python-template/leetcode/editor/cn/merge-two-sorted-lists.py
node js-template/leetcode/editor/cn/merge-two-sorted-lists.js
```

## Code Architecture

### Project Structure

```text
lc-plugin-template/
├── cpp-template/              # C++ solutions (80+ problems)
│   ├── *.cpp                  # Individual problem files in root
│   ├── leetcode/
│   │   └── editor/
│   │       ├── common/        # Shared data structures
│   │       │   ├── ListNode.cpp
│   │       │   └── TreeNode.cpp
│   │       ├── cn/            # Chinese LeetCode solutions
│   │       └── en/            # English LeetCode solutions
│   ├── build/                 # CMake build output
│   └── CMakeLists.txt         # Auto-generates targets for each main()
├── python-template/           # Python solutions
├── go-template/               # Go solutions
├── java-template/             # Java solutions
├── js-template/               # JavaScript solutions
└── common/                    # Additional shared utilities
```

### CMake Build System

The CMakeLists.txt automatically:
1. Scans all `.cpp` files for `int main(` functions
2. Creates a separate executable target for each problem file
3. Builds a static `common` library from `leetcode/editor/common/*.cpp`
4. Uses MD5 hash for unique target names to avoid conflicts

### Common Data Structures

Located in `cpp-template/leetcode/editor/common/`:

- **ListNode**: Singly linked list with `createHead()`, `print()`, `freeList()`
- **TreeNode**: Binary tree with `createRoot()`, `print()`, `freeTree()`

Include paths in problem files:

```cpp
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
```

### Problem File Pattern

Each C++ problem file follows this structure:

```cpp
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * [1] 两数之和
 * ... LeetCode metadata ...
 */

#include <iostream>
#include <vector>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    // Solution implementation
};
// @lc code=end

int main() {
    Solution solution;
    // Test cases with cout output
    return 0;
}
```

## Development Guidelines

### Adding New Problems

1. Create new `.cpp` file in `cpp-template/` or `leetcode/editor/cn/`
2. Follow LeetCode plugin format with `@lc` comments
3. Include required headers from `../common/` if using ListNode/TreeNode
4. Add `main()` function with test cases
5. CMake will automatically detect and create build target

### Code Style

- Chinese filenames and comments for educational purposes
- Each file is self-contained and independently compilable
- Use `cout` for test output in `main()`
- Preserve `@lc code=start/end` markers for LeetCode plugin compatibility

### Testing

- Each file's `main()` contains multiple test cases
- Compile single files for quick testing
- Use CMake build to verify all solutions compile
- Do not batch modify include paths in existing files

### Project Conventions

- C++ file naming: `<id>.<name>.cpp` (some historical files have spaces)
- Problems are single-file, standalone, executable
- Shared code in `common/` should not be modified without justification
- Build artifacts in `build/` are not committed
