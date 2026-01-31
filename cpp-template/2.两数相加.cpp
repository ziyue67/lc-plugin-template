/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30305
 *
 * [2] 两数相加
 *
 * https://leetcode.cn/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (46.32%)
 * Likes:    11688
 * Dislikes: 0
 * Total Accepted:    2.7M
 * Total Submissions: 5.8M
 * Testcase Example:  '[2,4,3]\n[5,6,4]\n[0]\n[0]\n[9,9,9,9,9,9,9]\n[9,9,9,9]'
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 * 
 * 
 * 示例 2：
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 示例 3：
 * 
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 <= Node.val <= 9
 * 题目数据保证列表表示的数字不含前导零
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* cur = head;
        int carry = 0;
        while(l1 || l2 || carry) {
            int sum = carry;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        return head->next;
        
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

int main() {
    Solution solution;
    
    // 测试用例1: l1 = [2,4,3], l2 = [5,6,4]
    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});
    ListNode* res1 = solution.addTwoNumbers(l1, l2);
    cout << "测试用例1: ";
    printList(res1);
    cout << endl;
    
    // 测试用例2: l1 = [0], l2 = [0]
    ListNode* l3 = createList({0});
    ListNode* l4 = createList({0});
    ListNode* res2 = solution.addTwoNumbers(l3, l4);
    cout << "测试用例2: ";
    printList(res2);
    cout << endl;
    
    // 测试用例3: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    ListNode* l5 = createList({9, 9, 9, 9, 9, 9, 9});
    ListNode* l6 = createList({9, 9, 9, 9});
    ListNode* res3 = solution.addTwoNumbers(l5, l6);
    cout << "测试用例3: ";
    printList(res3);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */

