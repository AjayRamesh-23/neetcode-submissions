class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        nums_set = set(nums)
        result = 0
        length = 1
        for num in nums:
            if num - 1 not in nums_set:
                length = 1
                while num + length in nums_set:
                    length += 1
            result = max(length, result)
        return result
