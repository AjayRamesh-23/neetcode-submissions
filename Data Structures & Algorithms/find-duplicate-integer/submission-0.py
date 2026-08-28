class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        numbers_set = set()
        for num in nums:
            if num not in numbers_set:
                numbers_set.add(num)
            else:
                return num
        
        