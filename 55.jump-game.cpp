/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size() - 1;
        for (int i=nums.size() - 1; i>=0; i--){
            if (i + nums[i] >= lastPos){
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
};
// @lc code=end

