/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp = {{0,1}};
        int presum=0, count=0, search_num=0;
        for(int x : nums){
            presum+=x;
            search_num = presum - k;
            if (mp.count(search_num)){
                count+=mp[search_num];
            }
            mp[presum]++;
        }
        return count;
    }
};
// @lc code=end

