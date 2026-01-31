/*
 * @lc app=leetcode.cn id=26 lang=cpp
 * @lcpr version=30300
 *
 * [26] 删除有序数组中的重复项
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
    int removeDuplicates(vector<int>& nums) {
        // int p=nums.size();    
        // if(p==0)return 0;
        // int q=0;
        // for(int i=0;i<p;i++){
        //     if(nums[q] !=nums[i] ){
        //         nums[++q]=nums[i];
        //     }
        // }
        // return q+1;
// 1. 定义变量p，作为“去重后有效元素的尾指针”，初始值0（指向第一个有效元素）
    int p = 0;
// 2. 获取数组nums的长度n，避免循环中重复调用size()方法（提升效率）
    int n = nums.size();
// 3. 定义变量q作为“遍历指针”，从索引1开始（跳过第一个元素，与p指向的元素对比）
    for (int q = 1; q < n; ++q) {
    // 4. 核心判断：若q指向的元素与p指向的元素不同（说明找到新的有效元素）
        if (nums[p] != nums[q]) {
        // 5. p先自增1（移动到下一个有效元素的位置），再将q指向的新元素赋值给该位置
            nums[++p] = nums[q];
    }
    // 6. 若元素相同：不执行任何操作，q继续向后遍历（跳过重复元素）
}
// 7. 返回去重后的有效长度：p是有效元素的最后一个索引，长度需+1
return p + 1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    
    // 测试用例1: nums = [1,1,2]
    vector<int> nums1 = {1, 1, 2};
    int len1 = solution.removeDuplicates(nums1);
    cout << "测试用例1: 长度=" << len1 << ", nums=[";
    for (int i = 0; i < len1; i++) {
        cout << nums1[i];
        if (i < len1 - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // 测试用例2: nums = [0,0,1,1,1,2,2,3,3,4]
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int len2 = solution.removeDuplicates(nums2);
    cout << "测试用例2: 长度=" << len2 << ", nums=[";
    for (int i = 0; i < len2; i++) {
        cout << nums2[i];
        if (i < len2 - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */

