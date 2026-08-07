import string

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        word = ''
        punctuations = string.punctuation
        for i in s:
            if(i.isalnum()):
                word+=i

        l = 0
        r = len(word) - 1

        while(l <= r):
            if word[l] != word[r]:
                return False
            else:
                l = l + 1
                r = r - 1
        return True
        