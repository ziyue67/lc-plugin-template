/*
 * @lc app=leetcode.cn id=430 lang=cpp
 * @lcpr version=30400
 *
 * [430] 扁平化多级双向链表
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
Node *dfs(Node *node)
{
    // 第一步，判断第三节点是否为空
    Node *tmp = nullptr;
    if (node->child != nullptr)
    {                              // 当非空，则递归进入child列表
        if (node->next != nullptr) // 下一个位置不为空
        {
            tmp = node->next;
        } // 如果下一个位置为空，则tmp也为空

        node->child->prev = node; // 第三结点位置指向自己
        node->next = node->child; // 自己指向第三结点
        Node *k = node->child;    // 备份
        node->child = nullptr;    // 置空
        Node *dd = dfs(k);        // 进入下一个结点
        if (tmp != nullptr)       // 当主路不为空
        {
            dd->next = tmp;
            tmp->prev = dd;
            return dfs(tmp);
        }
        else
            return dd;
    }

    // 第二步，判断下一节点是否为空
    if (node->next != nullptr)
        return dfs(node->next);

    return node; // 当是尾结点, 返回自己
}
class Solution {
public:
    Node* flatten(Node* head) {
       if (head == nullptr) return head;
       dfs(head);
       return head;
    }
    
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

