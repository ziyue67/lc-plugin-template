/*
 * @lc app=leetcode.cn id=面试题 02.08 lang=cpp
 * @lcpr version=30400
 *
 * [面试题 02.08] 环路检测
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
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
        slow = head;
        while (slow != fast)
        {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
// @lc code=end



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

int main()
{
  auto createList = [](const vector<int> &vals, int pos) -> ListNode *
  {
    if (vals.empty())
      return nullptr;
    vector<ListNode *> nodes;
    for (int v : vals)
      nodes.push_back(new ListNode(v));
    for (size_t i = 0; i + 1 < nodes.size(); ++i)
      nodes[i]->next = nodes[i + 1];
    if (pos >= 0 && pos < (int)nodes.size())
      nodes.back()->next = nodes[pos];
    return nodes[0];
  };

  auto printOutcome = [](ListNode *head, ListNode *entry)
  {
    if (!entry)
    {
      cout << "no cycle" << endl;
      return;
    }
    int idx = 0;
    ListNode *p = head;
    while (p && p != entry)
    {
      p = p->next;
      ++idx;
    }
    cout << "tail connects to node index " << idx << endl;
  };

  Solution solution;

  vector<pair<vector<int>, int>> tests = {
      {{3, 2, 0, -4}, 1},
      {{1, 2}, 0},
      {{1}, -1},
  };

  for (auto &tc : tests)
  {
    ListNode *head = createList(tc.first, tc.second);
    ListNode *entry = solution.detectCycle(head);
    printOutcome(head, entry);
    // note: skipping deletion for brevity (process exit will reclaim memory)
  }

  return 0;
}
