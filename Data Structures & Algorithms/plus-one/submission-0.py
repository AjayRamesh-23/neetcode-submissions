class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        number = ""
        result = []
        for digit in digits:
            number+=str(digit)
        answer = str(int(number) + 1)
        for a in answer:
            result.append(a)
        return result
        