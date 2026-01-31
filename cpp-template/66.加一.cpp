/*
 * @lc app=leetcode.cn id=66 lang=cpp
 * @lcpr version=30305
 *
 * [66] 加一
 *
 * https://leetcode.cn/problems/plus-one/description/
 *
 * algorithms
 * Easy (47.26%)
 * Likes:    1560
 * Dislikes: 0
 * Total Accepted:    899.1K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,3]\n[4,3,2,1]\n[9]'
 *
 * 给定一个表示 大整数 的整数数组 digits，其中 digits[i] 是整数的第 i
 * 位数字。这些数字按从左到右，从最高位到最低位排列。这个大整数不包含任何前导 0。
 * 
 * 将大整数加 1，并返回结果的数字数组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：digits = [1,2,3]
 * 输出：[1,2,4]
 * 解释：输入数组表示数字 123。
 * 加 1 后得到 123 + 1 = 124。
 * 因此，结果应该是 [1,2,4]。
 * 
 * 
 * 示例 2：
 * 
 * 输入：digits = [4,3,2,1]
 * 输出：[4,3,2,2]
 * 解释：输入数组表示数字 4321。
 * 加 1 后得到 4321 + 1 = 4322。
 * 因此，结果应该是 [4,3,2,2]。
 * 
 * 
 * 示例 3：
 * 
 * 输入：digits = [9]
 * 输出：[1,0]
 * 解释：输入数组表示数字 9。
 * 加 1 得到了 9 + 1 = 10。
 * 因此，结果应该是 [1,0]。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 * digits 不包含任何前导 0。
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
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;

            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    
    // 测试用例1: digits = [1,2,3]
    vector<int> digits1 = {1, 2, 3};
    vector<int> res1 = solution.plusOne(digits1);
    cout << "测试用例1: [";
    for (int i = 0; i < res1.size(); i++) {
        cout << res1[i];
        if (i < res1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // 测试用例2: digits = [4,3,2,1]
    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> res2 = solution.plusOne(digits2);
    cout << "测试用例2: [";
    for (int i = 0; i < res2.size(); i++) {
        cout << res2[i];
        if (i < res2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // 测试用例3: digits = [9]
    vector<int> digits3 = {9};
    vector<int> res3 = solution.plusOne(digits3);
    cout << "测试用例3: [";
    for (int i = 0; i < res3.size(); i++) {
        cout << res3[i];
        if (i < res3.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [9]\n
// @lcpr case=end

 */

