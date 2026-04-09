/*
 * @lc app=leetcode.cn id=面试题 10.01 lang=cpp
 * @lcpr version=30402
 *
 * [面试题 10.01] 合并排序的数组
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
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
      int i=m-1,j=n-1,k=m+n-1; // i=A的尾元素, j=B的尾元素, k=合并后位置
      while(i>=0&&j>=0) A[k--]=(A[i]>B[j])?A[i--]:B[j--]; //从后往前 
      while(j>=0) A[k--]=B[j--]; //A数组剩余元素不用动
        
    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// [1,2,3,0,0,0]\n3\n[2,5,6]\n3\n
// @lcpr case=end

 */

