/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30305
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode.cn/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (74.90%)
 * Likes:    2528
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,3,4]\n[]\n[1]\n[1,2,3]'
 *
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 *
 *
 * 示例 2：
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：head = [1]
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 100] 内
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
    ListNode *swapPairs(ListNode *head)
    {
        // if(!head || !head->next)return head;
        // ListNode* newHead=head->next;//交换后的头节点
        // head->next=swapPairs(newHead->next); //递归
        // newHead->next=head; //交换
        // return newHead; //返回交换后的头节点
        ListNode *dummy = new ListNode(0, head); //哑节点
        ListNode *per = dummy; //前驱节点
        while (per->next && per->next->next) //遍历每对节点
        {
            ListNode *fast = per->next; //第一个节点
            ListNode *slow=per->next->next; //第二个节点
            per->next=slow; //交换 
            fast->next=slow->next; //连接后续节点
            slow->next=fast; //交换
            per=fast; //前驱节点后移
        }
        ListNode *newHead=dummy->next; //新的头节点
        delete dummy; //释放哑节点
        return newHead; 
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
