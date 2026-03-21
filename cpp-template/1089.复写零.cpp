/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 * @lcpr version=30401
 *
 * [1089] 复写零
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
  void duplicateZeros(vector<int> &arr)
  {
    // for(int i=0; i<arr.size();i++){ //遍历数组
    //   if(arr[i]==0){
    //     arr.pop_back(); //删除最后一个元素
    //     arr.insert(arr.begin() +i ,0); //在i位置插入0 
    //     i++; 
    //   }
    // }
    int n = arr.size();
    int count = 0; // 统计0的个数
    int last = 0;  // 最后一个不会溢出的位置

    // 第一遍：找到最后一个有效位置
    for (int i = 0; i < n; ++i)
    {
      if (i + count >= n)
        break; // 越界就停止
      last = i;
      if (arr[i] == 0)
        count++;
    }

    // 第二遍：从后向前复制
    for (int i = last; i >= 0; --i)
    {
      if (i + count < n)
        arr[i + count] = arr[i];
      if (arr[i] == 0)
      {
        count--;
        if (i + count < n)
          arr[i + count] = 0;
      }
    }
  }
};
// @lc code=end

int main()
{
  Solution solution;

  vector<int> arr1 = {1, 0, 2, 3, 0, 4, 5, 0};
  solution.duplicateZeros(arr1);
  for (int x : arr1)
    cout << x << " ";
  cout << "\n"; // [1,0,0,2,3,0,0,4]

  vector<int> arr2 = {1, 2, 3};
  solution.duplicateZeros(arr2);
  for (int x : arr2)
    cout << x << " ";
  cout << "\n"; // [1,2,3]

  vector<int> arr3 = {0, 0, 0, 0, 0, 0, 0};
  solution.duplicateZeros(arr3);
  for (int x : arr3)
    cout << x << " ";
  cout << "\n"; // [0,0,0,0,0,0,0]

  return 0;
}

/*
// @lcpr case=start
// [1,0,2,3,0,4,5,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
