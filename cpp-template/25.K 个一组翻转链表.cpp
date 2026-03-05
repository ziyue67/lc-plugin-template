/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30400
 *
 * [25] K 个一组翻转链表
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
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    int count = 0; //统计链表长度
    for (ListNode *cur = head; cur; cur = cur->next)  // 统计链表长度
    {
      count++;
    }
    ListNode dummy(0, head); // 哑节点
    ListNode *p0=&dummy; // 指向当前段的起始点
    ListNode *per=nullptr; // 指向当前段的末尾
    ListNode *cur=head; // 指向当前段的下一个节点


    for(int i=0;i<count/k;i++){ //循环count/k次，每次翻转k个节点
      for(int j=0;j<k;j++){ //翻转k个节点
        ListNode *next=cur->next; //记录下一段的起始点
        cur->next=per; //将当前节点连接到上一段
        per=cur; //将当前节点设置为上一段
        cur=next; //将当前节点设置为下一段
      }
      ListNode *next=p0->next;//记录下一段的起始点
      p0->next->next=cur;//将当前段连接到下一段
      p0->next=per;//将上一段连接到当前段
      p0=next;//将p0移动到下一段的起始点
    }
    return dummy.next;

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
  // [1,2,3,4,5]\n2\n
  // @lcpr case=end

  // @lcpr case=start
  // [1,2,3,4,5]\n3\n
  // @lcpr case=end

   */
