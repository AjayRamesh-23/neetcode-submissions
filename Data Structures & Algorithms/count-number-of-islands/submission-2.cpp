class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited, int rows, int cols){
        if(row < 0 || row >=rows || col < 0 || col >=cols || visited[row][col] || grid[row][col] == '0'){
            return;
        }
        visited[row][col] = 1;
        dfs(row - 1, col, grid, visited, rows, cols);
        dfs(row + 1, col, grid, visited, rows, cols);
        dfs(row, col - 1, grid, visited, rows, cols);
        dfs(row, col + 1, grid, visited, rows, cols);
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(i, j, grid, visited, rows, cols);
                    islands++;
                }
            }
        }
        return islands; 
    }
};
