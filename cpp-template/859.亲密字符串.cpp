/*
 * @lc app=leetcode.cn id=859 lang=cpp
 * @lcpr version=30403
 *
 * [859] 亲密字符串
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{
public:
  bool buddyStrings(string s, string goal)
  {
    if (s.size() != goal.size())
      return false;

    if (s == goal)
    {
      unordered_set<char> seen;
      for (char c : s)
      {
        if (seen.count(c))
        {
          return true;
        }
        seen.insert(c);
      }
      return false;
    }

    vector<int> diff;
    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] != goal[i])
      {
        diff.push_back(i);
      }
    }

    if (diff.size() != 2)
    {
      return false;
    }

    return s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
  }
};
// @lc code=end

int main()
{
  Solution solution;
  cout << boolalpha << solution.buddyStrings("abcaa", "abcbb") << endl; // false
  cout << boolalpha << solution.buddyStrings("ab", "ba") << endl;       // true
  cout << boolalpha << solution.buddyStrings("aa", "aa") << endl;       // true
}

/*
// @lcpr case=start
// "ab"\n"ba"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"aa"\n
// @lcpr case=end

 */
