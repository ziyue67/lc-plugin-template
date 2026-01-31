/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=30305
 *
 * [344] 反转字符串
 *
 * https://leetcode.cn/problems/reverse-string/description/
 *
 * algorithms
 * Easy (80.95%)
 * Likes:    988
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 1.3M
 * Testcase Example:  '["h","e","l","l","o"]\n["H","a","n","n","a","h"]'
 *
 * 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
 * 
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = ["h","e","l","l","o"]
 * 输出：["o","l","l","e","h"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = ["H","a","n","n","a","h"]
 * 输出：["h","a","n","n","a","H"]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] 都是 ASCII 码表中的可打印字符
 * 
 * 
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
    void reverseString(vector<char>& s) {
        int left=0;
        int right=s.size()-1;
        while (left <right)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
        
        
        
    }
};
// @lc code=end

// 辅助函数：打印字符数组
void printChars(vector<char>& s) {
    cout << "[";
    for (int i = 0; i < s.size(); i++) {
        cout << "\"" << s[i] << "\"";
        if (i < s.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    // 测试用例1: s = ["h","e","l","l","o"]
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(s1);
    cout << "测试用例1: ";
    printChars(s1);
    cout << endl;
    
    // 测试用例2: s = ["H","a","n","n","a","h"]
    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    solution.reverseString(s2);
    cout << "测试用例2: ";
    printChars(s2);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */

