/*
 * @lc app=leetcode.cn id=9 lang=cpp
 * @lcpr version=30300
 *
 * [9] 回文数
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
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false; 
        }
        int reversed = 0;

        
        while (x > reversed)
        {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
       
        return x == reversed || x == reversed / 10;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    cout << boolalpha;  
    cout << "测试用例 121: " << solution.isPalindrome(121) << endl;    
    cout << "测试用例 -121: " << solution.isPalindrome(-121) << endl;  
    cout << "测试用例 10: " << solution.isPalindrome(10) << endl;     
    cout << "测试用例 0: " << solution.isPalindrome(0) << endl;     
    return 0;
}

/*
// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// -121\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */
