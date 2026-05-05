/*
 * @lc app=leetcode.cn id=LCR 147 lang=cpp
 * @lcpr version=30403
 *
 * [LCR 147] 最小栈
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "stack"
using namespace std;

// @lc code=start
class MinStack
{
public:
  /** initialize your data structure here. */
  stack<int> A, B;
  MinStack()
  {
  }

  void push(int x)
  {
    A.push(x);
    if (B.empty() || x <= B.top())
    {
      B.push(x);
    }
  }

  void pop()
  {
    if (A.top() == B.top())
    {
      B.pop();
    }
    A.pop();
  }
  int top()
  {
    return A.top();
  }

  int getMin()
  {
    return B.top();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main()
{
  MinStack solution;
  // your test code here
}

/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */
