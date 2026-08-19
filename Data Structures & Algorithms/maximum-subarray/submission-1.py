import sys
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        maximum = float('-inf')
        subarray_sum = 0
        for num in nums:
            subarray_sum += num
            maximum = max(maximum, subarray_sum)
            if subarray_sum < 0:
                subarray_sum = 0
        return maximum

