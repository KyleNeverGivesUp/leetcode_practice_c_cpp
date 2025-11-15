/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> leftBrackets;
        std::unordered_map<char, char> pairings = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c: s){
            if (pairings.find(c) == pairings.end()){
                leftBrackets.push(c);
            }
            else {
                if (leftBrackets.empty()){
                    return false;
                }
                char topElement = leftBrackets.top();
                leftBrackets.pop();
                
                if (topElement != pairings.at(c)){
                    return false;
                }
            }
        }
        return leftBrackets.empty();
    }
};
// @lc code=end

