/*
 * @lc app=leetcode.cn id=942 lang=cpp
 * @lcpr version=30400
 *
 * [942] 增减字符串匹配
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
    vector<int> diStringMatch(string s) {
      vector<int>res;  //存储结果
      int min = 0, max = s.size(); //最小值和最大值
      for(auto &str:s){ //遍历字符串
        if(str == 'I'){ //如果字符为I，则将最小值加入结果，并将最小值加1
          res.push_back(min++);
        }
        else{ //如果字符为D，则将最大值加入结果，并将最大值减1
          res.push_back(max--); 
        }
      }
      res.emplace_back(min); //将最小值加入结果
      return res; //返回结果

        
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// "IDID"\n
// @lcpr case=end

// @lcpr case=start
// "III"\n
// @lcpr case=end

// @lcpr case=start
// "DDI"\n
// @lcpr case=end

 */

