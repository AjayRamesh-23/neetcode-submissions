class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operations = {"+", "-", "*", "/"}
        for token in tokens:
            if token not in operations:
                stack.append(token)
            else:
                v1 = int(stack.pop())
                v2 = int(stack.pop())
                if token == "+":
                    v = v2 + v1
                elif token == "-":
                    v = v2 - v1
                elif token == "*":
                    v = v2 * v1
                elif token == "/":
                    v = int(v2/v1)                
                stack.append(str(v))
        return int(stack[-1])




