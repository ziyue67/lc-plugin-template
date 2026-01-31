/*
 * @lc app=leetcode.cn id=LCR 171 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 171] 训练计划 V
 *
 * https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/description/
 *
 * algorithms
 * Easy (65.42%)
 * Likes:    712
 * Dislikes: 0
 * Total Accepted:    349.7K
 * Total Submissions: 534.6K
 * Testcase Example:  '8\n[3,7,2,8,9,5,1]\n[4,6,8,9,5,1]\n3\n2'
 *
 * 某教练同时带教两位学员，分别以链表 l1、l2
 * 记录了两套核心肌群训练计划，节点值为训练项目编号。两套计划仅有前半部分热身项目不同，后续正式训练项目相同。请设计一个程序找出并返回第一个正式训练项目编号。如果两个链表不存在相交节点，返回
 * null 。
 * 
 * 如下面的两个链表：
 * 
 * 
 * 
 * 在节点 c1 开始相交。
 * 
 * 输入说明：
 * 
 * intersectVal - 相交的起始节点的值。如果不存在相交节点，这一值为 0
 * 
 * l1 - 第一个训练计划链表
 * 
 * l2 - 第二个训练计划链表
 * 
 * skip1 - 在 l1 中（从头节点开始）跳到交叉节点的节点数
 * 
 * skip2 - 在 l2 中（从头节点开始）跳到交叉节点的节点数
 * 
 * 程序将根据这些输入创建链式数据结构，并将两个头节点 head1 和 head2
 * 传递给你的程序。如果程序能够正确返回相交节点，那么你的解决方案将被视作正确答案 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2,
 * skipB = 3
 * 输出：Reference of the node with value = 8
 * 解释：第一个正式训练项目编号为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为
 * [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB
 * = 1
 * 输出：Reference of the node with value = 2
 * 解释：第一个正式训练项目编号为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为
 * [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 * 输出：null
 * 解释：两套计划完全不同，返回 null。从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以
 * intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 如果两个链表没有交点，返回 null.
 * 在返回结果后，两个链表仍须保持原有的结构。
 * 可假定整个链表结构中没有循环。
 * 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
 * 本题与主站 160
 * 题相同：https://leetcode.cn/problems/intersection-of-two-linked-lists/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A=headA,*B=headB;
        while(A!=B){
            A=A?A->next:headB;
            B=B?B->next:headA;
            if (A == B)
                return A;
        }
        return A;
        
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

int main() {
    Solution solution;
    
    // 测试用例1: 两个不相交的链表
    ListNode* headA1 = createList({3, 7, 2, 8, 9, 5, 1});
    ListNode* headB1 = createList({4, 6, 8, 9, 5, 1});
    ListNode* res1 = solution.getIntersectionNode(headA1, headB1);
    cout << "测试用例1: " << (res1 ? to_string(res1->val) : "null") << endl;
    
    return 0;
}



/*
// @lcpr case=start
// 8\n[3,7,2,8,9,5,1]\n[4,6,8,9,5,1]\n3\n2\n
// @lcpr case=end

 */

