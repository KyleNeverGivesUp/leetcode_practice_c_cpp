#
# @lc app=leetcode id=316 lang=python3
#
# [316] Remove Duplicate Letters
#

# @lc code=start
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        remain_count = Counter(s)
        stack = []
        visited = set()
        for i in s:
            remain_count[i] -= 1
            if i in visited:
                continue
            while stack and stack[-1] > i and remain_count[stack[-1]] > 0:
                removed_char = stack.pop()
                visited.remove(removed_char)
            stack.append(i)
            visited.add(i)
        return "".join(stack)
        
# @lc code=end

