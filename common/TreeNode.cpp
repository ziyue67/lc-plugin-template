#ifndef TREENODE_H
#define TREENODE_H

// 二叉树节点结构定义
struct TreeNode {
    int val;                  // 节点存储的值
    TreeNode *left;           // 左子树指针
    TreeNode *right;          // 右子树指针

    // 构造函数（初始化节点）
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif // TREENODE_H