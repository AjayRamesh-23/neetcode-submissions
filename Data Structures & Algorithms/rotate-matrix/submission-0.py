class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        k = 0
        result = [[0 for col in range(n)] for row in range(n)]
        for j in range(n):
            l = 0
            for i in range(n - 1,-1,-1):
                result[k][l] = matrix[i][j]
                l = l + 1
            k = k + 1

        for i in range(n):
            for j in range(n):
                matrix[i][j] = result[i][j]



        