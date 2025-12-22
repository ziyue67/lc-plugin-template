/*
 * @lc app=leetcode.cn id=234 lang=cpp
 * @lcpr version=30305
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        ListNode*fast=head,*slow=head;//快慢指针找到中间节点
        while (fast!=nullptr&&fast->next!=nullptr) 
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*per=nullptr,*cur=slow;//反转链表 per为头节点1
        while(cur!=nullptr){
            ListNode*next=cur->next;//注意保存下一个节点
            cur->next=per;//反转cur per next 同步后移  反转当前节点的指针
            per=cur; // per向前移动
            cur=next; // cur向前移动
        }
        while(per!=nullptr&&head!=nullptr)//比较
        {
            if(per->val!=head->val){ // 不是回文链表
                return false;
            }
            per=per->next;
            head=head->next;

        }
        return true;
        
        
        
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

