/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> mp;
        for (int i:nums){
            if (mp.find(i) == mp.end()){
                mp[i] = 1;
            }else mp[i]+=1;
        }

        for (const pair<int, int>& j: mp){
            if (j.second > len / 2){
                return j.first;
            }
        }
        return 0;
    }
};
// @lc code=end

