/*
 * @lc app=leetcode.cn id=83 lang=cpp
 * @lcpr version=30305
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (54.72%)
 * Likes:    1244
 * Dislikes: 0
 * Total Accepted:    828.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,1,2]\n[1,1,2,3,3]'
 *
 * 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [1,1,2]
 * 输出：[1,2]
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [1,1,2,3,3]
 * 输出：[1,2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目在范围 [0, 300] 内
 * -100 <= Node.val <= 100
 * 题目数据保证链表已经按升序 排列
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr)
        {
            return nullptr;
        }
        ListNode* cur = head; //当前节点
        while (cur->next) //当前节点不为空
        {
            if(cur->next->val==cur->val){ //当前节点的下一个节点值等于当前节点值
                cur->next=cur->next->next; //当前节点的下一个节点指向下一个节点的下一个节点
            }
            else
            {
                cur=cur->next; //当前节点指向下一个节点
            }
            
        }
        return head;
        
        
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
    
    // 测试用例1: head = [1,1,2]
    ListNode* head1 = createList({1, 1, 2});
    ListNode* res1 = solution.deleteDuplicates(head1);
    cout << "测试用例1: ";
    printList(res1);
    cout << endl;
    
    // 测试用例2: head = [1,1,2,3,3]
    ListNode* head2 = createList({1, 1, 2, 3, 3});
    ListNode* res2 = solution.deleteDuplicates(head2);
    cout << "测试用例2: ";
    printList(res2);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,3]\n
// @lcpr case=end

 */

