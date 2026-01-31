/*
 * @lc app=leetcode.cn id=2469 lang=cpp
 * @lcpr version=30305
 *
 * [2469] 温度转换
 *
 * https://leetcode.cn/problems/convert-the-temperature/description/
 *
 * algorithms
 * Easy (75.13%)
 * Likes:    164
 * Dislikes: 0
 * Total Accepted:    139.7K
 * Total Submissions: 186K
 * Testcase Example:  '36.50\n122.11'
 *
 * 给你一个四舍五入到两位小数的非负浮点数 celsius 来表示温度，以 摄氏度（Celsius）为单位。
 * 
 * 你需要将摄氏度转换为 开氏度（Kelvin）和 华氏度（Fahrenheit），并以数组 ans = [kelvin, fahrenheit]
 * 的形式返回结果。
 * 
 * 返回数组 ans 。与实际答案误差不超过 10^-5 的会视为正确答案。
 * 
 * 注意：
 * 
 * 
 * 开氏度 = 摄氏度 + 273.15
 * 华氏度 = 摄氏度 * 1.80 + 32.00
 * 
 * 
 * 
 * 
 * 示例 1 ：
 * 
 * 输入：celsius = 36.50
 * 输出：[309.65000,97.70000]
 * 解释：36.50 摄氏度：转换为开氏度是 309.65 ，转换为华氏度是 97.70 。
 * 
 * 示例 2 ：
 * 
 * 输入：celsius = 122.11
 * 输出：[395.26000,251.79800]
 * 解释：122.11 摄氏度：转换为开氏度是 395.26 ，转换为华氏度是 251.798 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= celsius <= 1000
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
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.80 + 32.00};
    }
};
// @lc code=end

// 辅助函数：打印双精度数组
void printArray(vector<double>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    // 测试用例1: celsius = 36.50
    vector<double> res1 = solution.convertTemperature(36.50);
    cout << "测试用例1: ";
    printArray(res1);
    cout << endl;
    
    // 测试用例2: celsius = 122.11
    vector<double> res2 = solution.convertTemperature(122.11);
    cout << "测试用例2: ";
    printArray(res2);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// 36.50\n
// @lcpr case=end

// @lcpr case=start
// 122.11\n
// @lcpr case=end

 */

