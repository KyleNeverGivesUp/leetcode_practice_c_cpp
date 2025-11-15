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

            cout << "pop: "<< pop << endl;
            cout << "x: " << x << endl;
            // if (x < INT_MIN || x > INT_MAX || pop >= 8 || pop<=-7) return 0;
            if (x < INT_MIN || x > INT_MAX || rev * 10 + pop < INT_MIN || rev * 10 + pop > INT_MAX) return 0;
            pop = x % 10;
            x = x / 10;
            rev = rev * 10 + pop;
            cout << "rev: " << rev << endl;
        }
        cout << "final rev: " << rev << endl;
        return rev;
    }
};
// @lc code=end

