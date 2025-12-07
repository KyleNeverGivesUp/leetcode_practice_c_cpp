/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 1;
        int start =0;
        int n = s.size();
        for(int i=0; i<n; i++){
            int odd_len = search(s, i ,i);
            int even_len = search(s, i, i+1);
            int curr_len = max(odd_len, even_len);
            if (curr_len > max_len ){
                max_len = curr_len;
                  start = i - (curr_len -1)/2;
            }
        
        }
        return s.substr(start, max_len);
    }

    int search(string s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left -1;
    }
};
// @lc code=end

