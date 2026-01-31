/*
 * @lc app=leetcode.cn id=206 lang=cpp
 * @lcpr version=30305
 *
 * [206] 反转链表
 *
 * https://leetcode.cn/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (76.32%)
 * Likes:    4017
 * Dislikes: 0
 * Total Accepted:    2.6M
 * Total Submissions: 3.4M
 * Testcase Example:  '[1,2,3,4,5]\n[1,2]\n[]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [1,2]
 * 输出：[2,1]
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 <= Node.val <= 5000
 * 
 * 
 * 
 * 
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p=nullptr; 
        while(head){ //当前节点不为空
            ListNode *q=head->next; //临时节点保存下一个节点
            head->next=p; //当前节点指向前一个节点
            p=head; //前一个节点指向当前节点
            head=q; //当前节点指向下一个节点
        }
        return p; //返回前一个节点，因为最后一个节点是前一个节点
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
    
    // 测试用例1: head = [1,2,3,4,5]
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    ListNode* res1 = solution.reverseList(head1);
    cout << "测试用例1: ";
    printList(res1);
    cout << endl;
    
    // 测试用例2: head = [1,2]
    ListNode* head2 = createList({1, 2});
    ListNode* res2 = solution.reverseList(head2);
    cout << "测试用例2: ";
    printList(res2);
    cout << endl;
    
    // 测试用例3: head = []
    ListNode* head3 = nullptr;
    ListNode* res3 = solution.reverseList(head3);
    cout << "测试用例3: ";
    printList(res3);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

