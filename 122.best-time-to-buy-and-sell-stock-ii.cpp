/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Approach 1
        // int total = 0;
        // int valley = INT_MAX;
        // int peak = INT_MAX;
        // for(int i=0;i<prices.size();i++){
        //     if (prices[i] < peak){
        //         total += peak - valley;
        //         valley = prices[i];
        //         peak = valley;
        //     }else{
        //         peak = prices[i];
        //     }
        // }
        // return total += peak - valley;
        // Approach 2
        int total = 0;
        for (int i=1; i<prices.size(); i++){
            if (prices[i] > prices[i-1]){
                total += prices[i] - prices[i-1];
            }
        }
        return total;

    }
};
// @lc code=end

