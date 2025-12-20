/*
 * @lc app=leetcode.cn id=141 lang=cpp
 * @lcpr version=30304
 *
 * [141] 环形链表
 *
 * https://leetcode.cn/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (54.24%)
 * Likes:    2414
 * Dislikes: 0
 * Total Accepted:    1.8M
 * Total Submissions: 3.2M
 * Testcase Example:  '[3,2,0,-4]\n1\n[1,2]\n0\n[1]\n-1'
 *
 * 给你一个链表的头节点 head ，判断链表中是否有环。
 *
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos
 * 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
 *
 * 如果链表中存在环 ，则返回 true 。 否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：head = [1,2], pos = 0
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：head = [1], pos = -1
 * 输出：false
 * 解释：链表中没有环。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目范围是 [0, 10^4]
 * -10^5 <= Node.val <= 10^5
 * pos 为 -1 或者链表中的一个 有效索引 。
 *
 *
 *
 *
 * 进阶：你能用 O(1)（即，常量）内存解决此问题吗？
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
class Solution
{
public:
/**
 * 判断链表是否有环
 * @param head 链表的头节点指针
 * @return 如果有环返回true，否则返回false
 */
    bool hasCycle(ListNode *head)
    {

    // 使用快慢指针法，慢指针每次移动一步，快指针每次移动两步
        ListNode *slow = head;   // 慢指针，初始指向头节点
        ListNode *fast = head;   // 快指针，初始指向头节点
    // 循环条件：快指针和快指针的下一个节点都不为空
        while (fast && fast->next)
        { // 修改循环条件
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
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
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */
