# LeetCode 插件模板

一个多语言的 LeetCode 刷题模板库，提供 C++、Python、Go、Java 和 JavaScript 的题目解决方案，适合作为本地练习、教学演示与自动化评测模板。

## 项目简介

本项目整理了 LeetCode 经典算法题目的解决方案，包含完整的代码实现和常用数据结构模板，旨在帮助开发者快速开始刷题并提高编程能力。每个语言目录下多数文件为单文件答案（含注释），便于快速编译/运行。

## 目录结构（概要）

```
lc-plugin-template/
├── cpp-template/          # C++ 模板和题解（单文件或可用 CMake 构建）
├── python-template/       # Python 模板和题解
├── go-template/           # Go 模板和题解
├── java-template/         # Java 模板和题解
├── js-template/           # JavaScript 模板和题解
├── common/                # 通用数据结构定义（链表、树等）
├── build/                 # 构建辅助文件（compile_commands.json 等，通常不提交变更）
└── ctoon_example/         # 示例代码
```

更多细节参见项目根目录的 AGENTS.md（代理/自动化编辑须知）：

- AGENTS.md: ./AGENTS.md

## 快速开始（按语言）

### C++
- 单文件快速编译并运行（Linux/macOS）：
  - g++ -std=c++20 "cpp-template/<file>.cpp" -O2 -Wall -Wextra -o /tmp/out && /tmp/out
- Windows (cmd/PowerShell)：
  - g++ -std=c++20 "cpp-template/<file>.cpp" -O2 -Wall -Wextra -o out.exe && .\out.exe
- 使用 CMake（当需要构建多个目标或加入 GoogleTest）：
  - cmake -S cpp-template -B build -DCMAKE_BUILD_TYPE=Release
  - cmake --build build --config Release -- -j
- 注意：很多题目为单文件并可能直接包含 `../common/*.cpp`，在修改此类 include 时请谨慎（参见 AGENTS.md）。

#### C++ 题目分类（仅 C++，基于文件名关键词自动归类）

以下分类从 `cpp-template/` 目录中按文件名关键词（"链表"、"数组"、"字符串" 等）自动生成。可能存在少量误判或遗漏，若需更精确的人工分类可另行请求。

- 链表
  - cpp-template/817.链表组件.cpp
  - cpp-template/445.两数相加 II.cpp
  - cpp-template/1721.交换链表中的节点.cpp
  - cpp-template/148.排序链表.cpp
  - cpp-template/147.对链表进行插入排序.cpp
  - cpp-template/328.奇偶链表.cpp
  - cpp-template/143.重排链表.cpp
  - cpp-template/142.环形链表 II.cpp
  - cpp-template/86.分隔链表.cpp
  - cpp-template/24 两两交换链表中的节点.cpp
  - cpp-template/92.反转链表 II.cpp
  - cpp-template/237.删除链表中的节点.cpp
  - cpp-template/82.删除排序链表中的重复元素 II.cpp
  - cpp-template/面试题 02.06.回文链表.cpp
  - cpp-template/234 回文链表.cpp
  - cpp-template/面试题 02.03.删除中间节点.cpp
  - cpp-template/2.两数相加.cpp
  - cpp-template/面试题 02.07.链表相交.cpp
  - cpp-template/面试题 02.02.返回倒数第 k 个节点.cpp
  - cpp-template/面试题 02.01.移除重复节点.cpp
  - cpp-template/LCR 136.删除链表的节点.cpp
  - cpp-template/876.链表的中间结点.cpp
  - cpp-template/61.旋转链表.cpp
  - cpp-template/21.合并两个有序链表.cpp
  - cpp-template/206.反转链表.cpp
  - cpp-template/203.移除链表元素.cpp
  - cpp-template/19.删除链表的倒数第 N 个结点.cpp
  - cpp-template/160.相交链表.cpp
  - cpp-template/141.环形链表.cpp
  - cpp-template/1290 二进制链表转整数.cpp

- 数组
  - cpp-template/66.加一.cpp
  - cpp-template/75.颜色分类.cpp
  - cpp-template/283 移动零.cpp
  - cpp-template/88.合并两个有序数组.cpp
  - cpp-template/349两个数组的交集.cpp
  - cpp-template/350 两个数组的交集 II.cpp
  - cpp-template/27.移除元素.cpp
  - cpp-template/26.删除有序数组中的重复项.cpp
  - cpp-template/1.两数之和.cpp
  - cpp-template/287.寻找重复数.cpp
  - cpp-template/455.分发饼干.cpp

- 字符串
  - cpp-template/1456.定长子串中元音的最大数目.cpp
  - cpp-template/392.判断子序列.cpp
  - cpp-template/58.最后一个单词的长度.cpp
  - cpp-template/345 反转字符串中的元音字母.cpp
  - cpp-template/344.反转字符串.cpp
  - cpp-template/28.找出字符串中第一个匹配项的下标.cpp
  - cpp-template/14.最长公共前缀.cpp
  - cpp-template/125.验证回文串.cpp
  - cpp-template/9.回文数.cpp

- 树
  - （在 cpp-template/ 中未发现明确标注为“树”或包含“树”字样的题目文件。若有遗漏，请告知，我会补充。）

### Go
- 运行包内所有测试：
  - go test ./...
- 运行单个测试：
  - go test ./go-template/leetcode/editor/cn -run TestName
- 格式化：gofmt -w .

### Python
- 运行单文件脚本：
  - python3 python-template/leetcode/editor/cn/merge-two-sorted-lists.py
- pytest（若添加测试）：
  - pytest -q path/to/test_file.py::test_name
- 格式化：black .；导入排序：isort .

### JavaScript / Node
- 运行单文件：
  - node js-template/leetcode/editor/cn/merge-two-sorted-lists.js
- 测试（若添加）：
  - npx jest path/to/test.spec.js -t "test name"
- 格式化/校验：prettier --write .；eslint .

### Java (Maven)
- 构建：mvn -f java-template/pom.xml compile
- 测试：mvn -f java-template/pom.xml test

## 如何运行“单个测试”
- C++：编译并运行包含 main() 的单文件（示例见上）。
- Go：go test <pkg> -run TestName
- Python：pytest -q path/to/test_file.py::test_function
- Java：mvn -Dtest=TestClass#testMethod test
- JS (Jest)：npx jest path/to/test.spec.js -t "test name"

## 通用贡献指南

1. Fork 仓库
2. 新建分支：git checkout -b feature/short-description
3. 小而集中的提交，撰写有意义的 commit message
4. 推送并提交 PR，描述更改动机与影响范围

代码审查与变更注意事项：
- 遵循现有文件风格；不要在多数文件上一次性做大幅格式化（请仅格式化你改动的文件）。
- 不要提交构建产物（如完整的 build/ 输出）。
- 若要更改通用数据结构（如 ListNode/TreeNode），请先在 Issue 中说明理由。

## 开发与 CI 注意（给自动化代理/贡献者）
- 请参阅 AGENTS.md 获取针对 agent 的更详细规则（编辑前请先读取目标文件）。
- 若添加测试，请在 PR 描述中说明如何运行新增测试以及本地复现步骤。

## 许可证
本项目采用 MIT 许可证。

## 作者
**ziyue67** - https://github.com/ziyue67

---

如果你希望我把这些 README 改动推到一个分支并创建 PR，我可以在本地创建分支、提交并准备 PR 文案（不会自动 push/发布，除非你授权）。