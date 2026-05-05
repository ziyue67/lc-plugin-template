/*
 * @lc app=leetcode.cn id=682 lang=cpp
 * @lcpr version=30403
 *
 * [682] 棒球比赛
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
  int calPoints(vector<string> &operations)
  {
    stack<int> ans;
    int sum = 0;
    for (auto &num : operations)
    {
      if (num[0] == 'C')
      {
        ans.pop();
      }
      else if (num[0] == 'D')
      {
        ans.push(ans.top() * 2);
      }
      else if (num[0] == '+')
      {
        int num1 = ans.top();
        ans.pop();
        int num2 = num1 + ans.top();
        ans.push(num1);
        ans.push(num2);
      }
      else
      {
        ans.push(stoi(num));
      }
    }
    while (!ans.empty())
    {
      sum += ans.top();
      ans.pop();
    }
    return sum;
  }
};
// @lc code=end

int main()
{
  Solution solution;

  string line;
  if (!getline(cin, line))
    return 0;

  // Parse JSON-like input: ["5","2","C","D","+"]
  vector<string> ops;
  bool inQuote = false;
  string current;

  for (char c : line)
  {
    if (c == '"')
    {
      if (inQuote && !current.empty())
      {
        ops.push_back(current);
        current.clear();
      }
      inQuote = !inQuote;
    }
    else if (inQuote)
    {
      current += c;
    }
  }

  cout << solution.calPoints(ops) << endl;
  return 0;
}

/*
// @lcpr case=start
// ["5","2","C","D","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["5","-2","4","C","D","9","+","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["1","C"]\n
// @lcpr case=end

 */
