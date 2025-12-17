/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertIndex = 1;
        int count = 1;
        for (int i=1; i<nums.size(); i++){
            if (nums[i] == nums[i-1]) count++;
            else count = 1;
            if (count <= 2){
                nums[insertIndex++] = nums[i];
            }
        }
        return insertIndex;
    }
};
// @lc code=end

