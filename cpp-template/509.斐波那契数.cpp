/*
 * @lc app=leetcode.cn id=509 lang=cpp
 * @lcpr version=30305
 *
 * [509] 斐波那契数
 *
 * https://leetcode.cn/problems/fibonacci-number/description/
 *
 * algorithms
 * Easy (65.62%)
 * Likes:    881
 * Dislikes: 0
 * Total Accepted:    912.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '2\n3\n4'
 *
 * 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
 * 
 * F(0) = 0，F(1) = 1
 * F(n) = F(n - 1) + F(n - 2)，其中 n > 1
 * 
 * 
 * 给定 n ，请计算 F(n) 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 2
 * 输出：1
 * 解释：F(2) = F(1) + F(0) = 1 + 0 = 1
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 3
 * 输出：2
 * 解释：F(3) = F(2) + F(1) = 1 + 1 = 2
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 4
 * 输出：3
 * 解释：F(4) = F(3) + F(2) = 2 + 1 = 3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 30
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
    int fib(int n) {
           if (n < 2) {
            return n;
        }
        int p = 0, q = 0, r = 1;
        for (int i = 2; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    
    cout << "测试用例1: " << solution.fib(2) << endl;
    cout << "测试用例2: " << solution.fib(3) << endl;
    cout << "测试用例3: " << solution.fib(4) << endl;
    
    return 0;
}



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

