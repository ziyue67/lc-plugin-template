/*
 * @lc app=leetcode.cn id=2697 lang=cpp
 * @lcpr version=30402
 *
 * [2697] 字典序最小回文串
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    string makeSmallestPalindrome(string s) {
      int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
          if(s[i] !=s[j]){   //  如果两个字符不相等，则将两个字符都变为较小的那个
            if(s[i]<s[j]){   //  如果s[i] < s[j]，则将s[j]变为s[i]
              s[j] = s[i];   
            }
            else{            //  如果s[i] > s[j]，则将s[i]变为s[j]
              s[i] = s[j];    
            }
          }
          i++;
          j--;
        }
        return s;
        
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// "egcfe"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n
// @lcpr case=end

// @lcpr case=start
// "seven"\n
// @lcpr case=end

 */

