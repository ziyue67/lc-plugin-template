/*
 * @lc app=leetcode.cn id=148 lang=cpp
 * @lcpr version=30305
 *
 * [148] 排序链表
 *
 * https://leetcode.cn/problems/sort-list/description/
 *
 * algorithms
 * Medium (67.66%)
 * Likes:    2669
 * Dislikes: 0
 * Total Accepted:    830.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[4,2,1,3]\n[-1,5,3,4,0]\n[]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
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
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 * 
 * 
 * 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
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
// 归并排序

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *head2=midleNode(head); //找到中点并断开
        head=sortList(head); //递归排序前半部分
        head2=sortList(head2); //递归排序后半部分
        return merger(head,head2); //合并两个有序链表
      
    }
    ListNode *merger(ListNode *l1, ListNode *l2) //合并两个有序链表
    {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (l1 &&l2)
        {
            if(l1->val< l2->val){
                cur->next=l1;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        cur->next =l1 ?l1:l2;
        return dummy->next;
    }
    
    ListNode *midleNode(ListNode *head){ //找到链表中点并断开
        ListNode *fast = head, *slow = head, *per = head;
        while (fast && fast->next)
        {
            per = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        per->next = nullptr;
        return slow;
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
    
    // 测试用例1: head = [4,2,1,3]
    ListNode* head1 = createList({4, 2, 1, 3});
    ListNode* res1 = solution.sortList(head1);
    cout << "测试用例1: ";
    printList(res1);
    cout << endl;
    
    // 测试用例2: head = [-1,5,3,4,0]
    ListNode* head2 = createList({-1, 5, 3, 4, 0});
    ListNode* res2 = solution.sortList(head2);
    cout << "测试用例2: ";
    printList(res2);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

