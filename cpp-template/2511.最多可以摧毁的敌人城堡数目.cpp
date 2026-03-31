/*
 * @lc app=leetcode.cn id=2511 lang=cpp
 * @lcpr version=30402
 *
 * [2511] 最多可以摧毁的敌人城堡数目
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
    int captureForts(vector<int>& forts) {
      int ans=0;
      int prePos=-1;
      int preVal=0;
      for(int i=0;i<forts.size();i++){
        if(forts[i]){
          if(prePos>=0 && preVal!=forts[i]){
            ans=max(ans,i-prePos-1);
          }
          prePos=i;
          preVal=forts[i];
        }
      }
      return ans;
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// [1,0,0,-1,0,0,0,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,-1]\n
// @lcpr case=end

 */

