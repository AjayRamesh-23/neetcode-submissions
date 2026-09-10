class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        if not matrix:
            return None
        m = len(matrix)
        n = len(matrix[0])
        rows = set()
        columns = set()
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    rows.add(i)
                    columns.add(j)

        for row in rows:
            for j in range(n):
                matrix[row][j] = 0
        
        for i in range(m):
            for column in columns:
                matrix[i][column] = 0
                