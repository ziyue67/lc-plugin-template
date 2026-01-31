/*
 * @lc app=leetcode.cn id=147 lang=cpp
 * @lcpr version=30305
 *
 * [147] 对链表进行插入排序
 *
 * https://leetcode.cn/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (70.49%)
 * Likes:    729
 * Dislikes: 0
 * Total Accepted:    193.5K
 * Total Submissions: 274.5K
 * Testcase Example:  '[4,2,1,3]\n[-1,5,3,4,0]'
 *
 * 给定单个链表的头 head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。
 * 
 * 插入排序 算法的步骤:
 * 
 * 
 * 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
 * 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
 * 重复直到所有输入数据插入完为止。
 * 
 * 
 * 
 * 下面是插入排序算法的一个图形示例。部分排序的列表(黑色)最初只包含列表中的第一个元素。每次迭代时，从输入数据中删除一个元素(红色)，并就地插入已排序的列表中。
 * 
 * 对链表进行插入排序。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入: head = [4,2,1,3]
 * 输出: [1,2,3,4]
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入: head = [-1,5,3,4,0]
 * 输出: [-1,0,3,4,5]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 列表中的节点数在 [1, 5000]范围内
 * -5000 <= Node.val <= 5000
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head)return head;  // 如果链表为空，直接返回头指针
        ListNode *dummy = new ListNode(0);//创建一个虚拟头结点
        ListNode*curr=head;
        while (curr)
        {
            ListNode *perv = dummy; // 当前节点的前驱节点
            while (perv->next &&perv->next->val <curr->val) // 找到插入位置
            {
                perv = perv->next;
            }
            ListNode *next=curr->next; // 保存下一个节点
            // 插入节点
            curr->next=perv->next; // 插入节点
            perv->next=curr; // 插入节点
            curr=next; // 处理下一个节点
        }
        return  dummy->next;
        
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
    ListNode* res1 = solution.insertionSortList(head1);
    cout << "测试用例1: ";
    printList(res1);
    cout << endl;
    
    // 测试用例2: head = [-1,5,3,4,0]
    ListNode* head2 = createList({-1, 5, 3, 4, 0});
    ListNode* res2 = solution.insertionSortList(head2);
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

 */

