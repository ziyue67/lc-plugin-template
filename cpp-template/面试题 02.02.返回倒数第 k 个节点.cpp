/*
 * @lc app=leetcode.cn id=面试题 02.02 lang=cpp
 * @lcpr version=30305
 *
 * [面试题 02.02] 返回倒数第 k 个节点
 *
 * https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/description/
 *
 * LCCI
 * Easy (76.62%)
 * Likes:    154
 * Dislikes: 0
 * Total Accepted:    125.3K
 * Total Submissions: 163.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
 * 
 * 注意：本题相对原题稍作改动
 * 
 * 示例：
 * 
 * 输入： 1->2->3->4->5 和 k = 2
 * 输出： 4
 * 
 * 说明：
 * 
 * 给定的 k 保证是有效的。
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
    int kthToLast(ListNode* head, int k) {
        ListNode* per = head;
        ListNode* p= head;
        for (int i = 0; i < k; i++)
        {   
            p=p->next;
        }
        while(p){
            p=p->next;
            per=per->next;
        }
        return per->val;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

 */

