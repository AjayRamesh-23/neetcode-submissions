class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()
         || grid[i][j] == 0 || visited[i][j]){
            return 0;
        }
        int area;
        if(grid[i][j] == 1 && !visited[i][j]){
            visited[i][j] = 1;
            area = 1 +
                    dfs(i-1, j, grid, visited) +
                    dfs(i+1, j, grid, visited) +
                    dfs(i, j - 1, grid, visited) +
                    dfs(i, j + 1, grid, visited);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int area;
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = dfs(i, j, grid, visited);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
