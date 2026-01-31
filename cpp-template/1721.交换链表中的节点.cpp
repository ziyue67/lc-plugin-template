/*
 * @lc app=leetcode.cn id=1721 lang=cpp
 * @lcpr version=30305
 *
 * [1721] 交换链表中的节点
 *
 * https://leetcode.cn/problems/swapping-nodes-in-a-linked-list/description/
 *
 * algorithms
 * Medium (65.02%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    31.9K
 * Total Submissions: 49.2K
 * Testcase Example:  '[1,2,3,4,5]\n2\n[7,9,6,6,7,8,3,0,9,5]\n5'
 *
 * 给你链表的头节点 head 和一个整数 k 。
 *
 * 交换 链表正数第 k 个节点和倒数第 k 个节点的值后，返回链表的头节点（链表 从 1 开始索引）。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[1,4,3,2,5]
 *
 *
 * 示例 2：
 *
 * 输入：head = [7,9,6,6,7,8,3,0,9,5], k = 5
 * 输出：[7,9,6,6,8,7,3,0,9,5]
 *
 *
 * 示例 3：
 *
 * 输入：head = [1], k = 1
 * 输出：[1]
 *
 *
 * 示例 4：
 *
 * 输入：head = [1,2], k = 1
 * 输出：[2,1]
 *
 *
 * 示例 5：
 *
 * 输入：head = [1,2,3], k = 2
 * 输出：[1,2,3]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目是 n
 * 1 <= k <= n <= 10^5
 * 0 <= Node.val <= 100
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
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *dummy=new ListNode(0,head);
        ListNode *fast=dummy;
        ListNode *slow=dummy;
        for(int i=0;i<k;i++){ //fast先走k步
            fast=fast->next;
        }
        ListNode *first=fast; //记录正数第k个节点
        while (fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        swap(first->val,slow->val); //交换值
        return dummy->next;
        

        
        
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

int main()
{
    Solution solution;
    
    // 测试用例1: head = [1,2,3,4,5], k = 2
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    ListNode* res1 = solution.swapNodes(head1, 2);
    cout << "测试用例1: ";
    printList(res1);
    cout << endl;
    
    // 测试用例2: head = [7,9,6,6,7,8,3,0,9,5], k = 5
    ListNode* head2 = createList({7, 9, 6, 6, 7, 8, 3, 0, 9, 5});
    ListNode* res2 = solution.swapNodes(head2, 5);
    cout << "测试用例2: ";
    printList(res2);
    cout << endl;
    
    return 0;
}

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [7,9,6,6,7,8,3,0,9,5]\n5\n
// @lcpr case=end

 */
