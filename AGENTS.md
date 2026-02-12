# AGENTS.md

LeetCode 多语言刷题模板仓库，主要包含 C++ 题解。

## 项目特定约定

- **文件命名**: `<id>.<name>.cpp` 格式，如 `1.两数之和.cpp`
- **单文件架构**: 每个 `.cpp` 文件独立，包含自己的 `main()` 函数
- **Include 路径**: 题目文件使用 `#include "../common/ListNode.cpp"` 引入公共代码
- **两套 common**: `/common/` 和 `/cpp-template/leetcode/editor/common/`

## 构建命令

```bash
# C++ 单文件编译
g++ -std=c++20 "cpp-template/<file>.cpp" -O2 -Wall -Wextra -o out.exe && ./out.exe

# CMake 构建（支持所有 68 道题目）
cmake -S cpp-template -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release -- -j

# Go 测试
go test ./...

# Java 构建
mvn -f java-template/pom.xml compile
```

## 目录结构

- `cpp-template/`: C++ 题解（68 道）
- `python-template/`: Python 题解
- `go-template/`: Go 题解
- `java-template/`: Java 题解
- `js-template/`: JavaScript 题解
- `common/`: 公共数据结构（ListNode, TreeNode）

## 注意事项

- 不要批量修改现有文件的 include 方式
- 新增公共类型时创建头文件（`common/*.hpp`）
- 保留题目文件中的教学注释
