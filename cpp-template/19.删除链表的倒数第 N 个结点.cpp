/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30305
 *
 * [19] 删除链表的倒数第 N 个结点
 *
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (52.46%)
 * Likes:    3227
 * Dislikes: 0
 * Total Accepted:    2M
 * Total Submissions: 3.7M
 * Testcase Example:  '[1,2,3,4,5]\n2\n[1]\n1\n[1,2]\n1'
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [1], n = 1
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中结点的数目为 sz
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 * 
 * 
 * 
 * 
 * 进阶：你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(0,head); //创建一个虚拟头节点
        ListNode *fast=dummy; //创建一个快指针
        ListNode *slow=dummy; //创建一个慢指针
        for (int i = 0; i < n; i++) //快指针先走n步
        {
            fast=fast->next; //快指针先走n步
        }
        while(fast->next!=nullptr){ //快指针走到链表末尾时，慢指针指向倒数第n个节点的前一个节点
            fast=fast->next;    //快指针走到链表末尾时，慢指针指向倒数第n个节点的前一个节点
            slow=slow->next;    //快指针走到链表末尾时，慢指针指向倒数第n个节点的前一个节点
        }
        slow->next=slow->next->next;//删除倒数第n个节点
        ListNode *ans=dummy->next; //返回链表头节点
        delete dummy; //删除虚拟头节点
        return ans; //返回链表头节点
        


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
    
    // 测试用例1: head = [1,2,3,4,5], n = 2
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    ListNode* res1 = solution.removeNthFromEnd(head1, 2);
    cout << "测试用例1: ";
    printList(res1);
    cout << endl;
    
    // 测试用例2: head = [1], n = 1
    ListNode* head2 = createList({1});
    ListNode* res2 = solution.removeNthFromEnd(head2, 1);
    cout << "测试用例2: ";
    printList(res2);
    cout << endl;
    
    // 测试用例3: head = [1,2], n = 1
    ListNode* head3 = createList({1, 2});
    ListNode* res3 = solution.removeNthFromEnd(head3, 1);
    cout << "测试用例3: ";
    printList(res3);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */

