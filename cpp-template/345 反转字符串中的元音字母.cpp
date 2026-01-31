/*
 * @lc app=leetcode.cn id=345 lang=cpp
 * @lcpr version=30305
 *
 * [345] 反转字符串中的元音字母
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int left=0;
        int right=s.size()-1;
        unordered_set<char>charSet={'a','e','i','o','u','I','E','O','U','A'};// 元音字母集合
        while (left<right)
        {
            if(!charSet.count(s[left])){ // 左指针指向的字符不是元音
                left++; // 左指针右移 
            }
            else if(!charSet.count(s[right])){ 
                right--;
            }
            else{ // 两个指针都指向元音字母 
                swap(s[left],s[right]);  // 交换这两个元音字母
                left++;
                right--;
            }
            
        }
        return s;
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    
    // 测试用例1: s = "IceCreAm"
    cout << "测试用例1: " << solution.reverseVowels("IceCreAm") << endl;
    
    // 测试用例2: s = "leetcode"
    cout << "测试用例2: " << solution.reverseVowels("leetcode") << endl;
    
    return 0;
}



/*
// @lcpr case=start
// "IceCreAm"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

 */

