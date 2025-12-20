/*
 * @lc app=leetcode.cn id=27 lang=cpp
 * @lcpr version=30300
 *
 * [27] 移除元素
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
    int removeElement(vector<int> &nums, int val)
    {
        // int j=nums.size()-1;
        // for(int i=0;i<=j;i++){
        //     if(nums[i]==val){
        //         swap(nums[i],nums[j]);
        //         j--;
        //         i--;
        //     }
        // }
        // return j +1;

        // if(nums.empty()){
        //     return 0;
        // }

        // int *p=nums.data();
        // int *q=nums.data()+nums.size()-1;
        // while (p <=q)
        // {
        //     while (p<=q && *p!=val)
        //     {
        //        p++;
        //     }
        //     while (p <= q && *q == val) {
        //     q--;
        // }
        //     if(p<=q){
        //         *p=*q;
        //         p++;
        //         q--;
        //     }

        // }
        // return p-nums.data();

        int p = 0, q = nums.size() - 1;
        while (p <= q)
        {
            // 左指针找需要移除的val
            if (nums[p] != val)
            {
                p++;
                continue;
            }
            // 右指针找可保留的非val（此时left指向val，需用right覆盖）
            if (nums[q] == val)
            {
                q--;
                continue;
            }
            // 用右指针的非val覆盖左指针的val，同时移动双指针
            nums[p++] = nums[q--];
        }
        // 剩余元素个数（无需再减首地址）
        return p;
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
// [3,2,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2,3,0,4,2]\n2\n
// @lcpr case=end

 */
