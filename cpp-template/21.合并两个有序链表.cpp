/*
 * @lc app=leetcode.cn id=21 lang=cpp
 * @lcpr version=30305
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode.cn/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (68.09%)
 * Likes:    3936
 * Dislikes: 0
 * Total Accepted:    2.3M
 * Total Submissions: 3.3M
 * Testcase Example:  '[1,2,4]\n[1,3,4]\n[]\n[]\n[]\n[0]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 *
 *
 *
 * 示例 1：
 *
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 *
 *
 * 示例 2：
 *
 * 输入：l1 = [], l2 = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 两个链表的节点数目范围是 [0, 50]
 * -100 <= Node.val <= 100
 * l1 和 l2 均按 非递减顺序 排列
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // ListNode *last=new ListNode(-1); //创建一个虚拟头结点
        // ListNode *head = last; //保存头结点
        //    while (list1  &&list2 )
        //    {
        //      if(list1->val <list2->val){
        //          last->next = list1;
        //          list1 = list1->next;
        //          last = last->next;
        //      }
        //      else{
        //          last->next = list2;
        //          list2 = list2->next;
        //          last = last->next;
        //      }
        //    }
        //    if(list1){
        //        last->next = list1;
        //    }
        //    if(list2){
        //        last->next = list2;
        //    }
        //    ListNode *result=head->next; //返回头结点
        //    delete head; //释放内存
        //    return result; //返回头结点
        ListNode dummy(-1);   // 创建一个虚拟头结点
        ListNode *p = &dummy; // 保存头结点
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                p->next = list1;
                list1 = list1->next;
            }
            else
            {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        // if(list1){
        //     p->next = list1;
        // }
        // if(list2){
        //     p->next = list2;
        // }
        p->next =list1 ?list1:list2;//将剩余的节点连接到新链表的末尾 

        return dummy.next;

    };
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */
