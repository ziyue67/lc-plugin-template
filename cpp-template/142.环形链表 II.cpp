/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=30305
 *
 * [142] 环形链表 II
 *
 * https://leetcode.cn/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (62.39%)
 * Likes:    2933
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 2.2M
 * Testcase Example:  '[3,2,0,-4]\n1\n[1,2]\n0\n[1]\n-1'
 *
 * 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 *
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos
 * 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos
 * 不作为参数进行传递，仅仅是为了标识链表的实际情况。
 *
 * 不允许修改 链表。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：返回索引为 1 的链表节点
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：head = [1,2], pos = 0
 * 输出：返回索引为 0 的链表节点
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：head = [1], pos = -1
 * 输出：返回 null
 * 解释：链表中没有环。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目范围在范围 [0, 10^4] 内
 * -10^5 <= Node.val <= 10^5
 * pos 的值为 -1 或者链表中的一个有效索引
 *
 *
 *
 *
 * 进阶：你是否可以使用 O(1) 空间解决此题？
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
    ListNode *detectCycle(ListNode *head)
    {
        // ListNode *fast=head,*slow=head; //分别指向快慢指针
        // while (fast && fast->next) //遍历链表
        // {
        //     fast=fast->next->next; //快指针每次走两步
        //     slow=slow->next; //慢指针每次走一步
        //     if(fast==slow){ //快慢指针相遇，说明有环
        //         slow=head; //慢指针重新指向头节点
        //         while(slow!=fast){ //两个指针同时向前走，相遇点即为环的入口
        //             slow=slow->next; //慢指针每次走一步
        //             fast=fast->next; //快指针每次走一步
        //         }
        //         return slow; //返回环的入口节点
        //     }
        // }
        // return nullptr; //无环，返回空指针
        ListNode *fast = head, *slow = head;
        while (true)
        {
            if (fast == nullptr || fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
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
