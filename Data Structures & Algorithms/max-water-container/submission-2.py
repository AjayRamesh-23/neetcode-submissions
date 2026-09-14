class Solution:
    def maxArea(self, nums: List[int]) -> int:
        maximumArea = 0
        l = 0
        r = len(nums) - 1
        while l < r:
            width = r - l
            height = min(nums[l], nums[r])
            maximumArea = max(maximumArea, width * height)

            if nums[l] < nums[r]:
                l+=1
            elif nums[l] > nums[r]:
                r-=1
            else:
                r-=1
        return maximumArea

        