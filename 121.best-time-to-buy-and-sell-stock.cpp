/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_prices = INT_MAX;
        int size = prices.size();
        for (int i = 0; i < size; ++i){
            if (prices[i] < min_prices){
                min_prices = prices[i];
            }
            else if(prices[i] - min_prices > max_profit){
                max_profit = prices[i] - min_prices;
            }
        }
        return max_profit;
    }
};
// @lc code=end

