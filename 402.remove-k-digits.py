#
# @lc app=leetcode id=402 lang=python3
#
# [402] Remove K Digits
#

# @lc code=start
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        for i in num:
            while stack and k and stack[-1] > i:
                stack.pop()
                k -= 1
            stack.append(i)

        if k > 0:
            stack = stack[:-k]
        ret = "".join(stack).lstrip("0")
        return "0" if ret =="" else ret

# @lc code=end