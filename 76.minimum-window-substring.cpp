/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int count[256];
        int window[256];
        int required = 1;
        for ( char &cc : t){
            count[cc]++;
        }
        int len = s.length();
        for(int right=0; right< len; ++right){
            char sc = s[right];
            if (count[sc] !=0){
                window[sc]++;
            }
            for ( char &cc : t){
                if (window[cc] ==0){
                    required = 0;
                }
            }
        if (required == 1){
            left++;
        }


        }
        return ;
    }
};
// @lc code=end

