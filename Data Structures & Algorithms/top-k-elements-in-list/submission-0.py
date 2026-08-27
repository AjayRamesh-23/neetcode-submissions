class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashmap = {}
        result = []
        for num in nums:
            if num not in hashmap:
                hashmap[num] = 1
            else:
                hashmap[num] += 1
        sorted_hashmap = dict(sorted(hashmap.items(), key=lambda item: item[1], reverse=True))
        sorted_keys = list(sorted_hashmap.keys())
        return sorted_keys[:k]
        