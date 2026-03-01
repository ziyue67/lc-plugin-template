/*
 * @lc app=leetcode.cn id=725 lang=cpp
 * @lcpr version=30400
 *
 * [725] 分隔链表
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
  vector<ListNode *> splitListToParts(ListNode *head, int k)
  {
    int len = 0; // 计算链表长度
    ListNode *cur = head; // 计算链表长度
    ListNode *pre ; // 计算链表长度
    while (cur)  // 计算链表长度
    {
      len++;  
      cur = cur->next; 
    }
    vector<ListNode *> res(k, nullptr); // 初始化为nullptr
    int part = len / k;                 // 每个部分的基础长度
    int extra = len % k;                // 前extra个部分长度+1
    for (int i = 0; i < k; i++) // 遍历k个部分
    {
      for (int j = 0; j < part + (extra > 0); j++) // 遍历每个部分
      {
        if (j == 0) // 如果是第一个节点，则赋值给res[i]
        {
          res[i] = head; // 如果是第一个节点，则赋值给res[i]
        }
        pre = head; // 记录前一个节点
        head = head->next; // 移动到下一个节点
      }
      if(extra >0) extra--; // 如果还有剩余的节点，则extra减1
      if(head != nullptr){ // 如果head不为空，则将pre的next置为nullptr
        pre->next =nullptr;
      }
    }
    return res; 
  }
};
// @lc code=end

int main()
{
  auto createList = [](const vector<int> &vals) -> ListNode * {
    if (vals.empty()) return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *cur = head;
    for (size_t i = 1; i < vals.size(); ++i) {
      cur->next = new ListNode(vals[i]);
      cur = cur->next;
    }
    return head;
  };

  auto printParts = [](const vector<ListNode *> &parts) {
    cout << "[";
    for (size_t i = 0; i < parts.size(); ++i) {
      if (i) cout << ",";
      if (!parts[i]) { cout << "[]"; continue; }
      cout << "[";
      ListNode *p = parts[i];
      bool first = true;
      while (p) {
        if (!first) cout << ",";
        cout << p->val;
        first = false;
        p = p->next;
      }
      cout << "]";
    }
    cout << "]" << endl;
  };

  Solution solution;

  // 示例 1
  ListNode *h1 = createList({1,2,3});
  auto parts1 = solution.splitListToParts(h1, 5);
  printParts(parts1);

  // 示例 2
  ListNode *h2 = createList({1,2,3,4,5,6,7,8,9,10});
  auto parts2 = solution.splitListToParts(h2, 3);
  printParts(parts2);
}

/*
// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7,8,9,10]\n3\n
// @lcpr case=end

 */
