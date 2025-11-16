/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int p_check[26]={0};
        int s_window[26]={0};    
        int right = 0;
        int left = 0;
        int s_len = s.length();
        int p_len = p.length();
        vector<int> result;

        for (char c:p){
            p_check[c-'a']++; 
        }
        
        while(right < s_len){
            s_window[s[right] - 'a']++;
            right++;
            bool same = true;
            if (right - left == p_len){
                for (int i=0; i<26; i++){
                    if (p_check[i] != s_window[i]){
                        same = false;
                        break;
                    }
                }
                
                if (same) result.push_back(left);
                s_window[s[left] - 'a']--;
                left++;
            }
        
        }
        return result;
    }

};
// @lc code=end

