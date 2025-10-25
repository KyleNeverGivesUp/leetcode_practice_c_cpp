/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int pop = 0;
        int rev = 0;
        while (x !=0) {
            pop = x % 10;
            cout << pop << endl;
            x = x / 10;
            // if (x < INT_MIN || x > INT_MAX || pop >= 8 || pop<=-7) return 0;
            if (x < INT_MIN || x > INT_MAX || rev * 10 < INT_MIN || rev * 10 > INT_MAX) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
// @lc code=end

