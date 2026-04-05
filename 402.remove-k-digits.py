#
# @lc app=leetcode id=402 lang=python3
#
# [402] Remove K Digits
#

# @lc code=start
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        for digit in num:
            while stack and digit < stack[-1] and k:
                stack.pop()
                k -= 1
            stack.append(digit)
        
        if k:
            stack = stack[:-k]

        ret = "".join(stack).lstrip("0")
        return "0" if ret == "" else ret

# @lc code=end