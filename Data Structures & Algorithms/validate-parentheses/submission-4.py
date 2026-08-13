class Solution:
    def isValid(self, s: str) -> bool:
        n = len(s)
        print(n)
        if (n%2 != 0):
            return False
        stack = [s[0]]
        parentheses = {')':'(', '}':'{', ']':'['}
        i = 1
        while(i < n):
            if(s[i] not in [')', '}', ']']):
                stack.append(s[i])
            else:
                if(stack):
                    element = stack.pop()
                    if(parentheses.get(s[i]) != element):
                        return False
            i += 1
        if(stack):
            return False
        else:
            return True

        
        
# "([{}])"

# {
# [
# (

# element = {

#(){}}{



