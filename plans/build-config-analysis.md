# 构建配置分析报告

## 问题发现

### 1. CMakeLists.txt 问题

**问题描述**: 原始 CMakeLists.txt 只编译 `leetcode/editor/` 目录下的文件，忽略了根目录的 68 道题目。

**原因分析**: 
- `file(GLOB_RECURSE)` 只扫描了 `leetcode/editor/` 子目录
- 根目录的 `*.cpp` 文件未被包含在构建中

**解决方案**: 
- 添加 `file(GLOB ROOT_SOURCES "*.cpp")` 收集根目录文件
- 使用 MD5 哈希生成有效的目标名称，解决中文文件名问题

### 2. CMake 版本要求过高

**问题描述**: 原始配置要求 CMake 3.29，但许多系统只有 3.16+。

**解决方案**: 降低最低版本要求到 3.16。

### 3. .gitignore 配置问题

**问题描述**: 
- `*.json` 规则忽略了 `compile_commands.json`（LSP 需要）
- `build` 规则忽略了整个 build 目录

**解决方案**: 
- 添加 `!compile_commands.json` 例外
- 使用 `build/*` 配合 `!build/compile_commands.json` 保留 LSP 文件

## 修改内容

### cpp-template/CMakeLists.txt

```cmake
# 关键修改：使用 MD5 哈希生成目标名
string(MD5 name_hash "${source_file}")
string(SUBSTRING "${name_hash}" 0 8 hash_short)
set(target_name "lc_${hash_short}")
```

### .gitignore

```gitignore
# 保留 compile_commands.json 用于 LSP
*.json
!compile_commands.json

build/*
!build/compile_commands.json
```

## 验证结果

执行 CMake 构建后：
- 成功配置 68 个可执行目标
- 生成了 `build/compile_commands.json`
- 所有根目录题目文件都被正确编译

## 建议

1. **新增题目时**: 在 `cpp-template/` 目录创建 `<id>.<name>.cpp` 文件
2. **IDE 配置**: 确保 LSP 使用 `build/compile_commands.json`
3. **构建清理**: 使用 `cmake --build build --target clean` 清理构建产物
