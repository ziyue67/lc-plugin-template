/*
 * @lc app=leetcode.cn id=445 lang=cpp
 * @lcpr version=30305
 *
 * [445] 两数相加 II
 *
 * https://leetcode.cn/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (61.84%)
 * Likes:    791
 * Dislikes: 0
 * Total Accepted:    184.9K
 * Total Submissions: 299K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]\n[2,4,3]\n[5,6,4]\n[0]\n[0]'
 *
 * 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 
 * 
 * 示例1：
 * 
 * 
 * 
 * 输入：l1 = [7,2,4,3], l2 = [5,6,4]
 * 输出：[7,8,0,7]
 * 
 * 
 * 示例2：
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[8,0,7]
 * 
 * 
 * 示例3：
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表的长度范围为 [1, 100]
 * 0 <= node.val <= 9
 * 输入数据保证链表代表的数字无前导 0
 * 
 * 
 * 
 * 
 * 进阶：如果输入链表不能翻转该如何解决？
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <stack>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // stack<int> s1, s2;
        // while (l1) //将链表1的值全部压入栈中
        // {
        //     s1.push(l1->val);
        //     l1=l1->next;
        // }
        // while(l2){ //将链表2的值全部压入栈中
        //     s2.push(l2->val);
        //     l2=l2->next;
        // }
        // int carry=0; //进位
        // ListNode *ans=nullptr; //结果链表头指针
        // while (!s1.empty() || !s2.empty() || carry) //循环条件
        // {
        //     int sum=carry; //每次循环先加上进位
        //     if(!s1.empty()){
        //         sum=sum+s1.top();//取出栈顶元素
        //         s1.pop(); //弹出栈顶元素
        //     }
        //     if(!s2.empty()){
        //         sum=sum+s2.top();
        //         s2.pop();
        //     }
        //     carry=sum/10;
        //     ListNode *node=new ListNode(sum%10);
        //     node->next=ans;
        //     ans=node;
        // }
        // return ans;
        
        // 反转两个链表，使最低位在前
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        // 相加两个反转后的链表
        auto ans = addTwo(l1, l2);
        // 再次反转结果链表，使最高位在前
        return reverseList(ans);
    }

    // 递归反转链表
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        auto newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    // 递归相加两个链表，处理进位
    ListNode* addTwo(ListNode* l1, ListNode* l2, int carry = 0) {
        if (l1 == nullptr && l2 == nullptr) {
            // 如果有进位，创建新节点
            return carry ? new ListNode(carry) : nullptr;
        }
        if (l1 == nullptr) {
            // 交换以确保l1不为空
            swap(l1, l2);
        }
        // 计算当前位的和，包括进位
        carry += l1->val + (l2 ? l2->val : 0);
        // 更新当前节点的值
        l1->val = carry % 10;
        // 递归处理下一位
        l1->next = addTwo(l1->next, (l2 ? l2->next : nullptr), carry / 10);
        return l1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [7,2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

 */

