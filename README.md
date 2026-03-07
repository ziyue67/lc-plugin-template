# LeetCode 插件模板

一个多语言的 LeetCode 刷题模板仓库，包含 C++、Python、Go、Java、JavaScript 题解，适合本地练习、教学演示和自动化评测。

## 项目简介

本仓库按题目文件独立组织，便于快速定位、单题编译运行和跨语言对照学习。

- C++ 题解：`80` 题（每题单文件，均含 `main()` 测试）
- Python 题解：`3` 题
- Go 题解：`2` 题
- Java 题解：`2` 题
- JavaScript 题解：`2` 题

> 统计时间：2026-03-07（按仓库当前文件实际统计）

## 目录结构

```text
lc-plugin-template/
├── cpp-template/          # C++ 题解（80 题）
├── python-template/       # Python 题解（3 题）
├── go-template/           # Go 题解（2 题）
├── java-template/         # Java 题解（2 题）
├── js-template/           # JavaScript 题解（2 题）
├── common/                # 通用数据结构（ListNode / TreeNode）
├── ctoon_example/         # Ctoon 示例
├── AGENTS.md              # 自动化编辑约定
├── CLAUDE.md              # 项目开发说明
└── README.md
```

## C++ 题目清单（80 题）

当前 `cpp-template/` 题目文件如下：

```text
1.两数之和.cpp
2.两数相加.cpp
3.无重复字符的最长子串.cpp
5.最长回文子串.cpp
9.回文数.cpp
13.罗马数字转整数.cpp
14.最长公共前缀.cpp
15.三数之和.cpp
19.删除链表的倒数第 N 个结点.cpp
21.合并两个有序链表.cpp
24 两两交换链表中的节点.cpp
25.K 个一组翻转链表.cpp
26.删除有序数组中的重复项.cpp
27.移除元素.cpp
28.找出字符串中第一个匹配项的下标.cpp
58.最后一个单词的长度.cpp
61.旋转链表.cpp
66.加一.cpp
70.爬楼梯.cpp
75.颜色分类.cpp
82.删除排序链表中的重复元素 II.cpp
83.删除排序链表中的重复元素.cpp
86.分隔链表.cpp
88.合并两个有序数组.cpp
92.反转链表 II.cpp
125.验证回文串.cpp
136.只出现一次的数字.cpp
138.随机链表的复制.cpp
141.环形链表.cpp
142.环形链表 II.cpp
143.重排链表.cpp
146.LRU 缓存.cpp
147.对链表进行插入排序.cpp
148.排序链表.cpp
160.相交链表.cpp
202.快乐数.cpp
203.移除链表元素.cpp
206.反转链表.cpp
217.存在重复元素.cpp
219.存在重复元素 II.cpp
2235.两整数相加.cpp
234 回文链表.cpp
237.删除链表中的节点.cpp
2469.温度转换.cpp
258.各位相加.cpp
283 移动零.cpp
287.寻找重复数.cpp
328.奇偶链表.cpp
344.反转字符串.cpp
345 反转字符串中的元音字母.cpp
349两个数组的交集.cpp
350 两个数组的交集 II.cpp
392.判断子序列.cpp
430.扁平化多级双向链表 (看不懂 还没学到).cpp
445.两数相加 II.cpp
455.分发饼干.cpp
509.斐波那契数.cpp
541.反转字符串 II.cpp
705.设计哈希集合.cpp
725.分隔链表.cpp
817.链表组件.cpp
868.二进制间距.cpp
876.链表的中间结点.cpp
1137.第 N 个泰波那契数.cpp
1290 二进制链表转整数.cpp
1456.定长子串中元音的最大数目.cpp
1721.交换链表中的节点.cpp
LCR 123图书整理 I.cpp
LCR 136.删除链表的节点.cpp
LCR 140.训练计划 II.cpp
LCR 141.训练计划 III.cpp
LCR 142.训练计划 IV.cpp
LCR 171.训练计划 V.cpp
训练计划-iv.cpp
面试题 02.01.移除重复节点.cpp
面试题 02.02.返回倒数第 k 个节点.cpp
面试题 02.03.删除中间节点.cpp
面试题 02.06.回文链表.cpp
面试题 02.07.链表相交.cpp
面试题 02.08.环路检测.cpp
```

## 其他语言题目

### Python（3 题）

```text
BinaryTreePreorderTraversal .py
maximum-depth-of-binary-tree.py
merge-two-sorted-lists.py
```

### Go（2 题）

```text
binary-tree-preorder-traversal_test.go
merge_two_sorted_lists_test.go
```

### Java（2 题）

```text
BinaryTreePreorderTraversal.java
MergeTwoSortedLists.java
```

### JavaScript（2 题）

```text
binary-tree-preorder-traversal.js
merge-two-sorted-lists.js
```

## 快速开始

### C++ 单文件编译运行（推荐）

```bash
# Linux/macOS
g++ -std=c++20 "cpp-template/1.两数之和.cpp" -O2 -Wall -Wextra -o test && ./test

# Windows PowerShell
g++ -std=c++20 "cpp-template/1.两数之和.cpp" -O2 -Wall -Wextra -o test.exe; .\test.exe
```

### CMake 构建（cpp-template）

```bash
cmake -S cpp-template -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release -- -j
```

### 其他语言

```bash
# Go
go test ./...

# Python
python python-template/leetcode/editor/cn/merge-two-sorted-lists.py

# Java
mvn -f java-template/pom.xml compile

# JavaScript
node js-template/leetcode/editor/cn/merge-two-sorted-lists.js
```

## 项目约定

- C++ 文件命名格式：`<id>.<name>.cpp`（存在少量历史文件名含空格）
- C++ 题解为单文件结构，每个文件可独立编译运行
- 题目文件可通过 `#include "../common/ListNode.cpp"` 等方式复用公共结构
- 不要批量改动历史题解的 include 方式

## 贡献指南

1. Fork 仓库
2. 新建分支：`git checkout -b feature/short-description`
3. 保持小步提交并写清 commit message
4. 推送并发起 PR，说明改动动机和影响范围

提交前建议：

- 仅格式化你改动的文件
- 不提交构建产物（如 `build/` 内生成文件）
- 修改 `common/` 前先在 Issue 中说明理由

## 许可证

MIT License

## 作者

`ziyue67`  
<https://github.com/ziyue67>
