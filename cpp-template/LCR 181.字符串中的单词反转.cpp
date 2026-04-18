/*
 * @lc app=leetcode.cn id=LCR 181 lang=cpp
 * @lcpr version=30403
 *
 * [LCR 181] 字符串中的单词反转
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <sstream>
using namespace std;

// @lc code=start
class Solution
{
public:
  string reverseMessage(string message)
  {
    istringstream iss(message); //istringstream类用于将字符串流化
    string res,result;
    while(iss >> res){
      if(!result.empty()){
        result = res + " " +result; //注意空格  
      }
      else{
        result = res;
      }

    }
    return result;
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
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world!  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */
