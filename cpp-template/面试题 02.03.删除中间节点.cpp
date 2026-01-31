/*
 * @lc app=leetcode.cn id=面试题 02.03 lang=cpp
 * @lcpr version=30305
 *
 * [面试题 02.03] 删除中间节点
 *
 * https://leetcode.cn/problems/delete-middle-node-lcci/description/
 *
 * LCCI
 * Easy (86.00%)
 * Likes:    216
 * Dislikes: 0
 * Total Accepted:    111.1K
 * Total Submissions: 129.2K
 * Testcase Example:  '[4,5,1,9]\n5'
 *
 * 若链表中的某个节点，既不是链表头节点，也不是链表尾节点，则称其为该链表的「中间节点」。
 * 
 * 假定已知链表的某一个中间节点，请实现一种算法，将该节点从链表中删除。
 * 
 * 例如，传入节点 c（位于单向链表 a->b->c->d->e->f 中），将其删除后，剩余链表为 a->b->d->e->f
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：节点 5 （位于单向链表 4->5->1->9 中）
 * 输出：不返回任何数据，从链表中删除传入的节点 5，使链表变为 4->1->9
 * 
 * 
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val; //节点值替换
        node->next=node->next->next; //跳过下一个节点
    }
};
// @lc code=end

// 辅助函数：从vector创建链表
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for (int i = 1; i < vals.size(); i++) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]";
}

// 辅助函数：找到值为val的节点
ListNode* findNode(ListNode* head, int val) {
    while (head) {
        if (head->val == val) return head;
        head = head->next;
    }
    return nullptr;
}

int main() {
    Solution solution;
    
    // 测试用例1: 链表 [4,5,1,9], 删除节点 5
    ListNode* head1 = createList({4, 5, 1, 9});
    ListNode* node1 = findNode(head1, 5);
    solution.deleteNode(node1);
    cout << "测试用例1: ";
    printList(head1);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [4,5,1,9]\n5\n
// @lcpr case=end

 */

