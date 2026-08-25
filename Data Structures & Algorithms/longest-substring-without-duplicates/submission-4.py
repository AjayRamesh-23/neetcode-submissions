class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "":
            return 0
        n = len(s)
        longest = 0
        l = 0
        chars = set()

        for r in range(n):
            while s[r] in chars:
                chars.remove(s[l])
                l+=1
            chars.add(s[r])
            longest = max(longest, r-l+1)
        return longest
