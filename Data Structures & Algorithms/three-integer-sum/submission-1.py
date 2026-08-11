class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        right = len(nums) - 1
        index = 0
        results = []
        for index in range(len(nums) - 2):
            left = index + 1
            right = len(nums) - 1
            result = [nums[index]]
            while(left < right):
                if(nums[index] + nums[left] + nums[right] > 0):
                    right = right - 1
                elif(nums[index] + nums[left] + nums[right] < 0):
                    left = left + 1
                else:
                    result.append(nums[left])
                    result.append(nums[right])
                    left = left + 1
                    right = right - 1
                    if result not in results:
                        results.append(result)
                    result = [nums[index]]
        return results
        