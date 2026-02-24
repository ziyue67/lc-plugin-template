/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30307
 *
 * [15] 三数之和
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3)
            return result;

        std::ranges::sort(nums);

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return result;
    }

};
// @lc code=end

    /*
    // @lcpr case=start
    // [-1,0,1,2,-1,-4]\n
    // @lcpr case=end

    // @lcpr case=start
    // [0,1,1]\n
    // @lcpr case=end

    // @lcpr case=start
    // [0,0,0]\n
    // @lcpr case=end

     */
