class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}
    
        for string in strs:
            sorted_string = ''.join(sorted(string))
            groups.setdefault(sorted_string, []).append(string)
        return list(groups.values())

        