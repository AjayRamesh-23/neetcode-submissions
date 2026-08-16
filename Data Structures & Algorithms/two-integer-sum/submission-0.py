class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        result = []
        for index in range(len(nums)):
            if target - nums[index] not in hashmap:
                hashmap[nums[index]] = index
            else:
                result.append(index)
                result.append(hashmap[target-nums[index]])
        result.sort()
        return result
