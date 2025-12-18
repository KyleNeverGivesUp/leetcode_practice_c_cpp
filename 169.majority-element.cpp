/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int i:nums){
            if (count == 0){
                candidate = i;
            }
            count += (candidate == i)? 1 : -1;
        }
        return candidate;
    }
};
// @lc code=end

