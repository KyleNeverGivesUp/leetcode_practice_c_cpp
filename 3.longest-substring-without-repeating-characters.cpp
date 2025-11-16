/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> st;
        int max_length = 0;
        int left = 0;
        for(int right =0; right< s.length(); right++){
            // cout<< s[i] << endl;
            char c = s[right];
            while (st.count(c)){
                st.erase(s[left]);
                left++;
            }
            st.insert(c);
            max_length = max(max_length, right-left+1);
        }
        return max_length;
    }
};
// @lc code=end

