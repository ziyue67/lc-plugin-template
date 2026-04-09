/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=30403
 *
 * [151] 反转字符串中的单词
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
  string reverseWords(string s)
  {
    // int n=s.size();  //字符串长度
    // int left=0,right=n-1; //双指针
    // while(left<=right &&s[left]==' ') left++; //去除左边空格
    // while(left<=right &&s[right]==' ') right--; //去除右边空格
    // int slow=0; //慢指针
    // while(left<=right){
    //     if(s[left]==' ' &&s[left-1]!=' '){ //遇到空格且前一个不是空格
    //         left++; //跳过空格
    //         continue;
    //     }
    //     s[slow++]=s[left++]; //将字符放入慢指针位置，同时慢指针后移
    // }
    // s.resize(slow); //截取字符串
    // return s;
    istringstream iss(s); // 使用istringstream分割字符串
    string res, result;
    while (iss >> res)
    { // 依次取出单词
      if (!result.empty())
        result = " " + result; // 如果结果不为空，则在前面加上空格
      result = res + result;   // 将单词加入结果字符串
    }
    return result; // 返回结果字符串
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
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */
