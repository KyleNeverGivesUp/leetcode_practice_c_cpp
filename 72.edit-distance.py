#
# @lc app=leetcode id=72 lang=python3
#
# [72] Edit Distance
#

# @lc code=start
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        r, c = len(word1) + 1, len(word2) + 1
        dp = [[0] * c for _ in range(r)]
        for i in range(r):
            dp[i][0] = i
        for j in range(c):
            dp[0][j] = j
        
        for i in range(1, r):
            for j in range(1, c):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1
        return dp[i-1][j-1]


# @lc code=end

