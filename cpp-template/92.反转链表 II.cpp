/*
 * @lc app=leetcode.cn id=92 lang=cpp
 * @lcpr version=30305
 *
 * [92] 反转链表 II
 *
 * https://leetcode.cn/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (57.97%)
 * Likes:    2034
 * Dislikes: 0
 * Total Accepted:    703.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4,5]\n2\n4\n[5]\n1\n1'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right
 * 的链表节点，返回 反转后的链表 。
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目为 n
 * 1 <= n <= 500
 * -500 <= Node.val <= 500
 * 1 <= left <= right <= n
 * 
 * 
 * 
 * 
 * 进阶： 你可以使用一趟扫描完成反转吗？
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0,head); //哑节点
        ListNode *perv=&dummy; //前驱节点
        for (int i = 0; i < left - 1; i++) //找到前驱节点   
        {
            perv=perv->next; //前驱节点后移
        }
        ListNode *cur=perv->next; //当前节点
        for (int i = 0; i < right - left; ++i) //反转链表
        {
            ListNode *next = cur->next; //下一个节点
            cur->next = next->next; //当前节点指向下下个节点
            next->next = perv->next; //下一个节点指向前驱节点的下一个节点
            perv->next = next; //前驱节点指向下一个节点
        }

        return dummy.next; //返回头节点
        
        
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
    
    // 测试用例1: head = [1,2,3,4,5], left = 2, right = 4
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    ListNode* res1 = solution.reverseBetween(head1, 2, 4);
    cout << "测试用例1: ";
    printList(res1);
    cout << endl;
    
    // 测试用例2: head = [5], left = 1, right = 1
    ListNode* head2 = createList({5});
    ListNode* res2 = solution.reverseBetween(head2, 1, 1);
    cout << "测试用例2: ";
    printList(res2);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */

